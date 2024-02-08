/*Definicion de macros y codigo C literal*/

%{
    #include "lexico.h"
    #include <stdio.h>
    int errores = 0;    
    void error_lexico(); /*predeclaracion de la funcion para evitar warning  */
%}
/*Macors de expresiones regulares*/
D [0-9]
/*_ es para pq algunas palabras van asi separadas*/
L [a-zA-Z_]
/*MODO PANICO*/
ERROR [^0-9a-zA-Z_ \t\n\r;{}()=+\-*/,"]+
/* Opciones de flex */
/* Activando el conteo correcto de instrucciones*/
%option yylineno
%x comentario
/* la x es para que lo ejecute a parte del automata principal del resto d expresiones*/
/*Expresiones regulares de tokens*/
%%

"main"                          {return MAIN; }
"{"                             {return LLAVI; }
"}"                             {return LLAVD; }
"print"                         {return PRIN; }
{L}({L}|{D})*                   {return IDEN; }
"+"                             {return SUMA; }
"-"                             {return REST; }
"*"                             {return MULT; }
"/"                             {return DIVI; }
"="                             {return IGUA; }
{D}+                            {return ENTE; }
";"                             {return PYCO; }
,                               {return COMA; }
"("                             {return PARI; }
")"                             {return PARD; }
"//".*                          {}
"/*"                            {BEGIN(comentario); } 
<comentario>"*/"                {BEGIN(INITIAL); }
<comentario>.|\n                {}
["]([^"\n]|\\\")*["]            {return CADN; }
[ \t\r\n]+                      {}
["]([^"\n]|\\\")*               {error_lexico(); }
{ERROR}                         {error_lexico(); }

%%
void error_lexico(){
    printf("Error en linea %d: %s\n",yylineno, yytext);
    errores++;
}