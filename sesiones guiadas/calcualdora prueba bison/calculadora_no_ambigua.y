%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    extern int yylex();
    extern int yylineno;
    void yyerror(const char* msg);
    int regs[10];
    void inicializar_regs();
    void asignar_reg(char *reg, int valor);
    int leer_reg(char *reg);
    void imprimir_regs();
%}

/* Tipo de dato de valores semánticos */
%union {
    int entero;
    char *cadena;
}

%token SUMA "+"
%token RESTA "-"
%token PROD "*"
%token DIVI "/"
%token PARD ")"
%token PARI "("
%token <entero> NUME "numero"
%token PYCO ";"
%token IGUA "="
%token <cadena> REG "registro"

/* Tipo de dato de los no terminales */
%type <entero> expresion termino factor

%define parse.error verbose

%%
/*
E -> E + T | E - T | T
T -> T * F | T / F | F
F -> (E) | num
*/

entrada   : inicializar lista     { imprimir_regs();    }
          ;

inicializar : %empty              { inicializar_regs(); }
            ;

lista     : linea                 { printf("Li->L\n");    }
          | lista linea           { printf("Li->Li L\n"); }
          ;

linea     : expresion ";"         { printf("L->E [%d];\n", $1);  }
          | REG "=" expresion ";" { printf("L->R %s=E\n",$1);
                                    asignar_reg($1,$3);
                                  }
          ;

expresion : expresion "+" termino { printf("E->E+T\n"); 
                                    $$ = $1 + $3;
                                  }
          | expresion "-" termino { printf("E->E-T\n"); 
                                    $$ = $1 - $3;
                                  }
          | termino               { printf("E->T\n");   
                                    $$ = $1;
                                  }
          ;

termino   : termino "*" factor    { printf("T->T*F\n");
                                    $$ = $1 * $3;
                                  }
          | termino "/" factor    { printf("T->T/F\n");
                                    $$ = $1 / $3;
                                  }
          | factor                { printf("T->F\n");  
                                    $$ = $1;
                                  }
          ;

factor    : "(" expresion ")"     { printf("F->(E)\n");
                                    $$ = $2;
                                  }
          | NUME                  { printf("F->num [%d]\n", $1);
                                    $$ = $1;
                                  }
          | "-" factor            { printf("F->-F\n)");
                                    $$ = -$2;
                                  }
          | REG                   { printf("F->REG %s\n",$1);
                                    $$ = leer_reg($1);
                                  }
          ;

%%

void yyerror(const char* msg) {
    printf("Error en linea %d: %s\n", yylineno, msg);
}

void inicializar_regs() {
    memset(regs,0,10*sizeof(int));
}

void asignar_reg(char *reg, int valor) {
    // reg es una cadena de la forma r\d
    int idx = atoi(&(reg[1]));
    regs[idx] = valor;
}

int leer_reg(char *reg) {
    int idx = atoi(&(reg[1]));
    return regs[idx];
}

void imprimir_regs() {
    for (int i = 0; i < 10; i++) {
        printf("r%d=%d\n", i, regs[i]);
    }
}
