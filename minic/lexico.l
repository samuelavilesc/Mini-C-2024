/*Definicion de macros y codigo C literal*/

%{
    #include "sintactico.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    int errores = 0;
    void error_lexico(); /*predeclaracion de la funcion para evitar warning  */
%}
/*Macros de expresiones regulares*/
D [0-9]
/*_ es para pq algunas palabras van asi separadas*/
L [a-zA-Z_]
/*MODO PANICO*/
ERROR [^0-9a-zA-Z_ \t\n\r;{}()=+\-*/,"]+

ESCAPE \\\*|\\\\|\\\"|\\[ntr]
/* Opciones de flex */
/* Activando el conteo correcto de instrucciones*/
%option yylineno
%x comentario
/* la x es para que lo ejecute a parte del automata principal del resto d expresiones*/
/*Expresiones regulares de tokens*/
%%
"var"                           {return var; }
"const"                         {return CONST; }
"if"                            {return IF; }
"else"                          {return ELSE; }
"while"                         {return WHILE; }
"read"                          {return READ; }
"{"                             {return LLAVI; }
"}"                             {return LLAVD; }
"print"                         {return PRINT; }
{L}({L}|{D})*                   {if(yyleng < 32){
                                    yylval.cadena=strdup(yytext);
                                    return id; 
                                }else error_lexico("La longitud de un identificador supera el límite.");}
"+"                             {return SUMA; }
"-"                             {return REST; }
"*"                             {return PROD; }
"/"                             {return DIVI; }
"="                             {return IGUA; }
{D}+                            {if(atol(yytext)<=pow(2,31)){ 
                                    yylval.cadena=strdup(yytext);
                                    return NUME;} 
                                 else error_lexico("Entero demasiado largo"); }
";"                             {return PYCO; }
,                               {return COMA; }
"("                             {return PARI; }
")"                             {return PARD; }
"//".*                          {}
"/*"                            {BEGIN(comentario); } 
<comentario>"*/"                {BEGIN(INITIAL); }
<comentario>.|\n                {}
["]([^"\n\\]|{ESCAPE})*["]      {yylval.cadena=strdup(yytext); return string; }
[ \t\r\n]+                      {}
["]([^"\n\\]|{ESCAPE})*        {error_lexico("Fallo en el cierre de comillas"); }
{ERROR}                         {error_lexico("Caracter invalido."); }

%%
void error_lexico(char *msg){
    printf("Error en linea %d - %s %s\n",yylineno, yytext,msg);
    errores++;
}