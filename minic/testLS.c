#include "listaSimbolos.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {

  // Creacion de la lista
  Lista l = creaLS();

  // Insercion de una constante "a" con valor 0.
  Simbolo aux;
  aux.nombre = "a";
  aux.tipo = CONSTANTE;
  insertaLS(l,finalLS(l),aux);

  // Insercion de una variable "b" con valor 1.
  aux.nombre = "b";
  aux.tipo = VARIABLE;
  insertaLS(l,finalLS(l),aux);
  
  // Busqueda del si­mbolo "b"
  PosicionLista p = buscaLS(l,"b");
  if (p != finalLS(l)) {
    Simbolo aux = recuperaLS(l,p);
    printf("Encontrado b, tipo: %s\n",(aux.tipo == VARIABLE ? "variable" : "constante"));
  }
  else {
    printf("No encontrado b\n");
  }

  // Busqueda de un si­mbolo "c"
  p = buscaLS(l,"c");
  if (p != finalLS(l)) {
    Simbolo aux = recuperaLS(l,p);
    printf("Encontrado c, tipo: %s\n",(aux.tipo == VARIABLE ? "variable" : "constante"));
  }
  else {
    printf("No encontrado c\n");
  }

  // Recorrido de la lista de simbolos
  printf("Imprimiendo lista de %d simbolos\n",longitudLS(l));
  p = inicioLS(l);
  while (p != finalLS(l)) {
    Simbolo aux = recuperaLS(l,p);
    char *tipo;
    switch (aux.tipo) {
        case VARIABLE:
            tipo = "variable";
            break;
        case CONSTANTE:
            tipo = "constante";
            break;
        default:
            tipo = "otro";
    }
    printf("%s es %s\n",aux.nombre,tipo);    
    p = siguienteLS(l,p);
  }

  // Liberacion de memoria de la lista.
  liberaLS(l);
}