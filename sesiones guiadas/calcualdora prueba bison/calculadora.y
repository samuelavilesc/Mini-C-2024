%{
    #include <stdio.h>
    extern int yylex();
    extern int yylineno;
    extern char* yytext;
    void yyerror(const char* msg);

%}

%token SUMA "+" 
%token PROD "*" 
%token RESTA "-"
%token DIVI "/"
%token PARI "("
%token PARD ")"
%token NUME "numero"
%token PYCO ";"

%define parse.error verbose
%%

/*
E -> E + T | E - T | T
T -> T * F | T / F | F
F -> ( E ) | num
*/
lista : linea  {printf("Li->L\n");}
      | lista linea {printf("Li->Li\n");}
      ;
linea : expresion ";" {printf("L-> E;\n");}
    ;
    /* en las expresiones los numeros identificados son $1 $2 $3 va incrementando*/
expresion: expresion "+" termino {printf("E->E+T\n");}
        | expresion "-" termino {printf("E->E-T\n");}
        | termino {printf("E->T\n");}
    ;
termino: termino "*" factor {printf("T->T*F\n");}
        | termino "/" factor {printf("T->T/F\n");}
        | factor {printf("T->F\n");}
    ;
factor: "(" expresion ")" {printf("F->(E)\n");}
        | NUME {printf("F->num[%d]\n",$1);}
        | "-" factor {printf("F->-F\n");}
    ;
%%
void yyerror(const char* msg){
    printf("Error en la linea %d: %s\n",yylineno, msg);
}