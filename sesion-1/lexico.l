/*Definicion de macros y codigo C literal*/

%{
    #include "lexico.h"
    #include <stdio.h>
    int errores = 0;    
    void error_lexico(); /*predeclaracion de la funcion para evitar warning  */
%}
D [0-9]
L [a-zA-Z_]
/* Opciones de flex */
/* Activando el conteo correcto de instrucciones*/
%option yylineno
/*Expresiones regulares de tokens*/
%%
"print"              {return PRIN; }
{L}({L}|{D})*        {return IDEN; }
"+"                  {return SUMA; }
"-"                  {return REST; }
"*"                  {return MULT; }
"/"                  {return DIVI; }
"="                  {return IGUA; }
{D}+                 {return ENTE; }
";"                  {return PYCO; }
"("                  {return PARI; }
")"                  {return PARD; }


[ \t\r\n]+           {}
.                    {error_lexico();}
"//".*               {}
%%
void error_lexico(){
    printf("Error en linea %d: %s\n",yylineno, yytext);
    errores++;
}
int main(int argc, char *argv[]){
    int token;
    while((token=yylex()) != 0){
        printf("Token: %d,%s\n",token,yytext);
    }
}