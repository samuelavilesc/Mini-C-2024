%{
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    //Lista simbolos
    #include "listaSimbolos.h"
    #include "listaCodigo.h"
    Lista ls;
    Tipo t;
    void insertaID(char * id,int val);
    void imprimeLS();
    int numStr=1;
    void insertarString(char* cadena, int val);
    void buscarID(char* id, int variable);
    extern int yylex();
    extern int yylineno;
    void yyerror(const char* msg);
    extern int errores;
    int analisis_ok();
    //tabla registros lidbres
    char registros[10];
    void inicializarReg();
    // devuelve $tX
    char *obtenerReg(); //obtener un registro libre
    //Argumento $tX
    void liberarReg(char *reg); //liberar un registro despues de usarlo
    //concatenar dos strings
    char* concatena(char* str1, char* str2);
    //funcion de prueba para imprimir lista de codigo
    void imprimirLC(ListaC codigo);
%}


/* Tipo de dato de valores semánticos */
%union {
    
    char *cadena;
    ListaC codigo;
}

%code requires {
 #include "listaCodigo.h"
}

%token <cadena> id "id"
%token <cadena> string "string"
%token <cadena> NUME "const"
%token var
%token CONST
%token IF "if"
%token ELSE "else"
%token WHILE "while"
%token PRINT "print" 
%token READ "read"
%token SUMA "+"
%token REST "-"
%token PROD "*"
%token DIVI "/"
%token PARD ")"
%token PARI "("
%token PYCO ";"
%token IGUA "="
%token COMA ","
%token LLAVI "{"
%token LLAVD "}"

/* Tipo de dato de los no terminales */
%type <codigo> expression

%define parse.error verbose
%define parse.trace
/* precedencia y asociatividad de operadores */
%left "+" "-"
%left "*" "/"
%precedence UMINUS /* precedencia para el operador unario - */
/*%left precedencia izquierda
%right precedencia derecha
%nonassoc precedencia no asociativa
*/
//Se espera un conflicto d/r
%expect 1

//$$ = cima de la pila
%%
program: {ls = creaLS(); inicializarReg();} 
        id "(" ")" "{" declarations statement_list "}"       {
            if(errores==0){
                imprimeLS();
            }
            liberaLS(ls);
        }
        ;       
declarations:     %empty        {} 
            | declarations var {t=VARIABLE;} identifier_list ";"        {}
            | declarations CONST{t=CONSTANTE;} identifier_list ";"        {}
            ;       
identifier_list: identifier       {}
               | identifier_list "," identifier       {}
               ;       
identifier: id        {insertaID($1,0);}
          | id "=" expression       {insertaID($1,0);}
          ;       
statement_list:  %empty         {}
              | statement_list statement        {}
              ;       
statement: id "=" expression ";"        {buscarID($1,1);
                                        //pruebas
                                        if(analisis_ok()) {
                                          imprimirLC($3);
                                        }
                                        }
         | "{" statement_list "}"       {}
         | "if" "(" expression ")" statement else_part  {}
         |"while" "(" expression ")" statement        {}
         | "print" "(" print_list ")" ";"       {}
         | "read" "(" read_list ")" ";"       {}
         ;        
else_part:  %empty      {}
            | "else" statement        {}
            ;
print_list: print_item        {}
          | print_list "," print_item       {}
          ;      
print_item: expression        {}
          | string        {insertarString($1,numStr);}
          ;         
read_list: id       {buscarID($1,1);}
          | read_list "," id        {buscarID($3,1);}
          ;       
expression: expression "+" expression       {
                                            if(analisis_ok()){
                                              $$=$1;
                                              concatenaLC($$,$3);
                                              Operacion op;
                                              op.op="add";
                                              op.res=recuperaResLC($1);
                                              op.arg1=recuperaResLC($1);
                                              op.arg2=recuperaResLC($3);
                                              insertaLC($$,finalLC($$),op);
                                              liberaLC($3);
                                              liberarReg(op.arg2);
                                            }
                                            }
         | expression "-" expression        {
                                            if(analisis_ok()){
                                              $$=$1;
                                              concatenaLC($$,$3);
                                              Operacion op;
                                              op.op="sub";
                                              op.res=recuperaResLC($1);
                                              op.arg1=recuperaResLC($1);
                                              op.arg2=recuperaResLC($3);
                                              insertaLC($$,finalLC($$),op);
                                              liberaLC($3);
                                              liberarReg(op.arg2);
                                            }
                                            }
         | expression "*" expression        {
                                            if(analisis_ok()){
                                              $$=$1;
                                              concatenaLC($$,$3);
                                              Operacion op;
                                              op.op="mul";
                                              op.res=recuperaResLC($1);
                                              op.arg1=recuperaResLC($1);
                                              op.arg2=recuperaResLC($3);
                                              insertaLC($$,finalLC($$),op);
                                              liberaLC($3);
                                              liberarReg(op.arg2);
                                            }
                                            }
         | expression "/" expression        {
                                             if(analisis_ok()){
                                              $$=$1;
                                              concatenaLC($$,$3);
                                              Operacion op;
                                              op.op="div";
                                              op.res=recuperaResLC($1);
                                              op.arg1=recuperaResLC($1);
                                              op.arg2=recuperaResLC($3);
                                              insertaLC($$,finalLC($$),op);
                                              liberaLC($3);
                                              liberarReg(op.arg2);
                                            }
                                            }
         | "-" expression %prec UMINUS        {
                                              //operacion neg $tx,$ty pone en tx el negativo de ty
                                              if(analisis_ok()){
                                                $$=$2;
                                                Operacion op;
                                                op.op="neg";
                                                op.res=recuperaResLC($2);
                                                op.arg1=recuperaResLC($2);
                                                op.arg2=NULL;
                                                insertaLC($$,finalLC($$),op);
                                                guardaResLC($$,op.res);
                                              }
                                              }
         |"(" expression ")"        { $$ = $2; }
         | NUME       {
                      if(analisis_ok){
                        $$=creaLC();
                        Operacion op;
                        op.op="li";
                        op.res = obtenerReg();
                        op.arg1=$1;
                        op.arg2=NULL;
                        insertaLC($$,finalLC($$),op); //donde la inserto,en que posicion, el que guardo
                        guardaResLC($$,op.res);
                      }
                      }
         | id       {buscarID($1,0);
                      if(analisis_ok){
                        $$=creaLC();
                        Operacion op;
                        op.op="lw";
                        op.res = obtenerReg();
                        op.arg1=concatena("_",$1);
                        op.arg2=NULL;
                        insertaLC($$,finalLC($$),op);
                        guardaResLC($$,op.res);
                      }
                      
                    }
         ;
%%      

void yyerror(const char* msg) {
    printf("Error en linea %d: %s\n", yylineno, msg);
}

void insertaID(char* id,int val){
    PosicionLista p = buscaLS(ls,id);
  if (p == finalLS(ls)) {
    Simbolo aux;
    aux.nombre=id;
    aux.tipo = t;
    aux.valor=val;
    insertaLS(ls,finalLS(ls),aux);
  }else{
    printf("Error: identificador %s redeclarado en línea %d\n",id,yylineno);
    errores++;
  }
}

void insertarString(char* cadena,int num){
    Simbolo aux;
    aux.nombre=cadena;
    aux.tipo = CADENA;
    aux.valor=num;
    numStr++;
    insertaLS(ls,finalLS(ls),aux);
}

void buscarID(char* id, int variable){
    PosicionLista p = buscaLS(ls,id);
  if (p != finalLS(ls)) {
    if(variable==1){
        Simbolo aux = recuperaLS(ls,p);
        if(aux.tipo!=VARIABLE){
            errores++;
            printf("Error: identificador %s es constante en línea %d\n",id,yylineno);
        }
    }
  }
  else {
    errores++;
    printf("Error: identificador %s no declarado, se usa en la línea:  %d\n",id,yylineno);
  }
}
int analisis_ok(){
  return errores==0;
}
void imprimeLS(){
  printf(".data\n");
  PosicionLista p = inicioLS(ls);
  while (p != finalLS(ls)) {
    Simbolo aux = recuperaLS(ls,p);
    if(aux.tipo==CADENA){
        printf("$str%d: .asciiz %s\n",aux.valor,aux.nombre);    
    }else{
        printf("_%s .word %d\n",aux.nombre,aux.valor);    
    }
    p = siguienteLS(ls,p);
  }
}

void inicializarReg(){
  for(int i=0;i<10;i++){
    registros[i]=0;
  }
}
// devuelve $tX
char *obtenerReg(){
  for(int i=0;i<10;i++){
    if(registros[i]==0){
      registros[i]=1;
      char* reg;
      //printf en una posicion de memoria que yo le digo, el puntero a la cadena de caracteres que se va
      //a montar
      asprintf(&reg,"$t%d",i); //sirve como para hacer la concatenación, guarda la cadena en la memoria apuntada por la variable
      return reg;
    }
  }
  printf("Error registros temporales agotados!\n");
  exit(1);
}
//Argumento $tX
void liberarReg(char *reg){
  int idx = atoi(&(reg[2])); //posicion 3 de la cadena $=pos0 t=pos1 X=pos2
  registros[idx]=0;
}
char* concatena(char* str1, char* str2){
  char* aux;
  asprintf(&aux,"%s%s",str1,str2);
  return aux;
}
void imprimirLC(ListaC codigo){
  PosicionListaC p = inicioLC(codigo);
  Operacion oper;
 while (p != finalLC(codigo)) {
  oper = recuperaLC(codigo,p);
  printf("%s",oper.op);
  if (oper.res) printf(" %s",oper.res);
  if (oper.arg1) printf(",%s",oper.arg1);
  if (oper.arg2) printf(",%s",oper.arg2);
  printf("\n");
  p = siguienteLC(codigo,p);
 }
}