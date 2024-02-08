#include <stdio.h>
extern int yylex();
extern char* yytext;

int main(int argc, char *argv[]){
    int token;
    while((token=yylex()) != 0){
        printf("Token: %d,%s\n",token,yytext);
    }
}