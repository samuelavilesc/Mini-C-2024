%{
    #include "calculadora.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h> 
    
%}
%option yylineno
%%
[ \n\t\r]+ ;
"+"       {return SUMA;}
"-"       {return RESTA;}
"*"       {return PROD;}
"/"       {return DIVI;}
"("       {return PARI;}
")"       {return PARD;}
";"       {return PYCO;}
"="       {return IGUA;}
"r"[0-9]+ {yylval.cadena = strdup(yytext); return REG;}
[0-9]+    {yylval.entero = atoi(yytext); return NUME;}
.         {printf("Caracter no valido en linea: %d %s\n",yylineno,yytext);}
%%