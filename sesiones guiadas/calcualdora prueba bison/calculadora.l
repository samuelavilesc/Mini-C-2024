%{
    #include "calculadora.tab.h"
    #include <stdio.h>  
    
%}
%option yylineno
%%
[ \n\t\r]+ ;
"+" {return SUMA;}
"-" {return RESTA;}
"*" {return PROD;}
"/" {return DIVI;}
"(" {return PARI;}
")" {return PARD;}
";" {return PYCO;}
[0-9]+ { yylval = atoi(yytext); return NUME;}
. {printf("Caracter no valido en linea: %d %s\n",yylineno,yytext);}
%%