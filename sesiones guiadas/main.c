#include <stdio.h>
extern int yylex();
extern char* yytext;
extern FILE* yyin;

int main(int argc, char *argv[]){
    FILE *fin=NULL;
    if(argc != 2){
        printf("Uso: %s <fichero>\n",argv[0]);
        return 1;
    } 
    fin = fopen(argv[1],"r");
    if(fin == NULL){
        printf("Error al abrir el fichero %s\n",argv[1]);
        return 2;
    }
    yyin = fin;
    
    int token;
    while((token=yylex()) != 0){
        printf("Token: %d - %s\n",token,yytext);
    }
    fclose(fin);
}