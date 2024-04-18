#include <stdio.h>
extern int yyparse();
extern char* yytext; //analizador sintáctico
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
    int res = yyparse();
    //printf("Resultado yyparse: %d\n",res);
    fclose(fin);
}