#include <stdio.h>
#include <string.h>
#include "banco.h"

ERROS novo(Operacao operacoes[], int *pos){
  if(*pos >= TOTAL)
    return MAX_CLIENTES;

  printf("Insira o nome do cliente: ");
}