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
    int contador_etiq=1;
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
    char* nuevaEtiqueta();
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
%token DO "do"
%token FOR "for"
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
%token DOSP ":"

/* Tipo de dato de los no terminales */
%type <codigo> expression statement statement_list declarations identifier_list identifier print_item print_list read_list else_part

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
            if(analisis_ok()){
                imprimeLS();
                concatenaLC($6,$7);
                imprimirLC($6); //la accion en mitad de la regla cuenta como simbolo
            }
            liberaLS(ls);
        }
        ;       
declarations:     %empty        {$$=creaLC();} 
            | declarations var {t=VARIABLE;} identifier_list ";"        {
                if(analisis_ok()){
                    $$=$1;
                    concatenaLC($$,$4);
                    liberaLC($4);
                }
            }
            | declarations CONST{t=CONSTANTE;} identifier_list ";"        {
                if(analisis_ok()){
                  $$=$1;
                  concatenaLC($$,$4);
                  liberaLC($4);
                }
               
            }
            | declarations var error ";" {$$=creaLC();}
            | declarations CONST error ";" {$$=creaLC();}
            ;

identifier_list: identifier       {
  if(analisis_ok()){
    $$=$1;
  }
  }
               | identifier_list "," identifier       {
                                                      if(analisis_ok()){
                                                      $$=$1;
                                                      concatenaLC($$,$3);
                                                      liberaLC($3);
                                                      }
                                                      }
               ;       
identifier: id        {insertaID($1,0);
                      if(analisis_ok()){
                        $$=creaLC();
                      }
                      }
          | id "=" expression       {insertaID($1,0);
                                    if(analisis_ok()){
                                      $$=$3;
                                      Operacion  op;
                                      op.op="sw";
                                      op.res=recuperaResLC($3);
                                      op.arg1=concatena("_",$1);
                                      op.arg2=NULL;
                                      insertaLC($$,finalLC($$),op);
                                      liberarReg(op.res);
                                    }
                                    }
          ;       
statement_list:  %empty         {
                                if(analisis_ok()){
                                  $$=creaLC();
                                }
                                }
              | statement_list statement {
                if(analisis_ok()){
                  $$ = $1;
                  concatenaLC($$,$2);
                  liberaLC($2);
                }
              }
              ;       
statement: id "=" expression ";"        {buscarID($1,1);
                                        
                                        
                                        if(analisis_ok()) {
                                          $$ = $3;
                                          Operacion op;
                                          op.op = "sw";
                                          op.res = recuperaResLC($3);
                                          op.arg1 = concatena("_",$1);
                                          op.arg2 = NULL;
                                          insertaLC($$,finalLC($$),op);
                                          liberarReg(op.res);
                                        }
                                        }
         | error ";" {$$=creaLC();}
         | "{" statement_list "}"       {
                                          if(analisis_ok()){
                                            $$ = $2;
                                          }
                                          
                                        }
         | "if" "(" expression ")" statement else_part  {
          if(analisis_ok()){
          $$ = $3;
          Operacion op;
          char* etiqEndIf = nuevaEtiqueta();
          char* etiqElse = nuevaEtiqueta(); 
          op.op = "beqz";
          op.res = recuperaResLC($3);
          op.arg1 = etiqEndIf;
          op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          concatenaLC($$,$5);
          if($6!=NULL){
            op.op = "b";
            op.res = etiqElse;
            op.arg1 = op.arg2 = NULL;
            insertaLC($$,finalLC($$),op);
          }
          op.op = concatena(etiqEndIf,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          if($6!=NULL){ 
            concatenaLC($$,$6);
            liberaLC($6);
          }
          op.op = concatena(etiqElse,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          liberarReg(recuperaResLC($3));
          liberaLC($5);
         }
         }
         |"while" "(" expression ")" statement        {
          if(analisis_ok()){
          $$ = creaLC();
          Operacion op;
          char* etiqWhile = nuevaEtiqueta();
          char* etiqEndWhile = nuevaEtiqueta();
          op.op = concatena(etiqWhile,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          concatenaLC($$,$3);
          op.op = "beqz";
          op.res = recuperaResLC($3);
          op.arg1 = etiqEndWhile;
          op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          concatenaLC($$,$5);
          op.op = "b";
          op.res = etiqWhile;
          op.arg1 = op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          op.op = concatena(etiqEndWhile,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          liberarReg(recuperaResLC($3));
          liberaLC($3);
          liberaLC($5);
         }
         }
         | "for" "(" id "=" expression ":" expression ")" statement {
          buscarID($3,1);
          if(analisis_ok()){
          $$ = $5;
          Operacion op;
          char* etiqFor = nuevaEtiqueta();
          char* etiqEndFor = nuevaEtiqueta();
          op.op = "sw";
          op.res = recuperaResLC($5);
          op.arg1 = concatena("_",$3);
          op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          op.op = concatena(etiqFor,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          op.op = "lw";
          op.res = recuperaResLC($5);
          op.arg1 = concatena("_",$3);
          op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          concatenaLC($$,$7);
          op.op = "beq";
          op.res = recuperaResLC($5);
          op.arg1 = recuperaResLC($7);
          op.arg2 = etiqEndFor;
          insertaLC($$,finalLC($$),op);
          concatenaLC($$,$9);
          //hacemos el incremento
          op.op = "addi";
          op.res = recuperaResLC($5);
          op.arg1 = recuperaResLC($5);
          op.arg2 = "1";
          insertaLC($$,finalLC($$),op);
          //lo guardamos en la variable global
          op.op = "sw";
          op.res = recuperaResLC($5);
          op.arg1 = concatena("_",$3);
          op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          op.op = "b";
          op.res = etiqFor;
          op.arg1 = op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          op.op = concatena(etiqEndFor,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          }
          }
         | "do" statement "while" "(" expression ")" ";" {
          if(analisis_ok()){
          $$ = creaLC();
          Operacion op;
          char* etiqDo = nuevaEtiqueta();
          op.op = concatena(etiqDo,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          concatenaLC($$,$2);
          concatenaLC($$,$5);
          op.op = "bnez";
          op.res = recuperaResLC($5);
          op.arg1 = etiqDo;
          op.arg2 = NULL;
          insertaLC($$,finalLC($$),op);
          liberarReg(op.res);
          liberaLC($2);
          liberaLC($5);
          }
         }
         | "print" "(" print_list ")" ";"       {if(analisis_ok()) $$ = $3;}
         | "read" "(" read_list ")" ";"       {if(analisis_ok()) $$=$3;}
         ;        
else_part:  %empty      {$$ = NULL;}
            | "else" statement        {
              if(analisis_ok()){
                $$=$2;
              }
              }
            ;
print_list: print_item        {if(analisis_ok()) $$=$1;}
          | print_list "," print_item       {
            if(analisis_ok()){
            $$=$1;
            concatenaLC($$,$3);
            liberaLC($3);
            }
          }
          ;      
print_item: expression        {
                          if(analisis_ok()){
                            $$ = $1;
                            Operacion op;
                            op.op = "li";
                            op.res = "$v0";
                            op.arg1 = "1";
                            op.arg2 = NULL;
                            insertaLC($$,finalLC($$),op);
                            op.op = "move";
                            op.res = "$a0";
                            op.arg1 = recuperaResLC($1);
                            op.arg2 = NULL;
                            liberarReg(op.arg1);
                            insertaLC($$,finalLC($$),op);
                            op.op = "syscall";
                            op.res = op.arg1 = op.arg2 = NULL;
                            insertaLC($$,finalLC($$),op);
                            
                          }          
                          }
          | string        {
                          insertarString($1,numStr);
                          if(analisis_ok()){
                            $$ = creaLC();
                            Operacion op;
                            op.op = "la";
                            op.res = "$a0";
                            char* str;
                            asprintf(&str,"$str%d",numStr-1);
                            op.arg1 = str;
                            op.arg2 = NULL;
                            insertaLC($$,finalLC($$),op);
                            op.op = "li";
                            op.res = "$v0";
                            op.arg1 = "4";
                            op.arg2 = NULL;
                            insertaLC($$,finalLC($$),op);
                            op.op = "syscall";
                            op.res = op.arg1 = op.arg2 = NULL;
                            insertaLC($$,finalLC($$),op);
                          }          
                          }
          ;         
read_list: id       {buscarID($1,1);
                    if(analisis_ok()){
                      $$=creaLC();
                      Operacion op;
                      op.op="li";
                      op.res = "$v0";
                      op.arg1="5";
                      op.arg2=NULL;
                      insertaLC($$,finalLC($$),op);
                      op.op="syscall";
                      op.res=op.arg1=op.arg2=NULL;
                      insertaLC($$,finalLC($$),op);
                      op.op="sw";
                      op.res="$v0";
                      op.arg1=concatena("_",$1);
                      op.arg2=NULL;
                      insertaLC($$,finalLC($$),op);
                      liberarReg(op.res);
                    }
                    
                    }
          | read_list "," id        {
                                    buscarID($3,1);
                                    if(analisis_ok()){
                                      $$=$1;
                                      Operacion op;
                                      op.op="li";
                                      op.res = "$v0";
                                      op.arg1="5";
                                      op.arg2=NULL;
                                      insertaLC($$,finalLC($$),op);
                                      op.op="syscall";
                                      op.res=op.arg1=op.arg2=NULL;
                                      insertaLC($$,finalLC($$),op);
                                      op.op="sw";
                                      op.res="$v0";
                                      op.arg1=concatena("_",$3);
                                      op.arg2=NULL;
                                      insertaLC($$,finalLC($$),op);
                                      liberarReg(op.res);
                                      }
                                    }
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
        printf("_%s: .word %d\n",aux.nombre,aux.valor);    
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
  printf(".text\n.globl main\nmain:\n");
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
 printf("li $v0, 10\nsyscall\n");
}
char* nuevaEtiqueta(){
    char* etiq;
    asprintf(&etiq,"etiq%d",contador_etiq);
    contador_etiq++;
    return etiq;
}