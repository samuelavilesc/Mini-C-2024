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
    int errores=0;
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
%type <entero> expresion

%define parse.error verbose
/* precedencia y asociatividad de operadores */
%left "+" "-"
%left "*" "/"
%precedence UMINUS /* precedencia para el operador unario - */
/*%left precedencia izquierda
%right precedencia derecha
%nonassoc precedencia no asociativa
*/
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
          | error ";"             { errores++; } /*aplicar esto de error en minic suma 0.5*/
          ;

expresion : expresion "+" expresion { printf("E->E+E\n"); 
                                    $$ = $1 + $3;
                                  }
          | expresion "-" expresion { printf("E->E-E\n"); 
                                    $$ = $1 - $3;
                                  }
          | expresion "*" expresion    { printf("E->E*E\n");
                                    $$ = $1 * $3;
                                  }
          | expresion "/" expresion    { printf("E->E/E\n");
                                    $$ = $1 / $3;
                                  }
          |"(" expresion ")"     { printf("E->(E)\n");
                                    $$ = $2;
                                  }
          | NUME                  { printf("E->num [%d]\n", $1);
                                    $$ = $1;
                                  }
          | "-" expresion %prec UMINUS     { printf("E->-E\n)");
                                    $$ = -$2;
                                  }
          | REG                   { printf("E->REG %s\n",$1);
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
