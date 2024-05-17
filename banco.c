#include <stdio.h>
#include <string.h>
#include "banco.h"

ERROS novo(Operacao operacoes[], int *pos){
  if(*pos >= TOTAL)
    return MAX_CLIENTES;

  printf("Insira o nome do cliente: ");
  scanf("%s", operacoes[*pos].nome);

  printf("Insira o CPF do cliente: ");
  scanf("%d", operacoes[*pos].cpf);

  printf("Insira uma senha para a conta: ");
  scanf("%d", operacoes[*pos].senha);

  printf("Insira o tipo de conta (Comum ou Plus): ");
  if(*pos == COMUM)
    return COMUM;
  printf("Insira o saldo da conta: ");
  if(*pos == PLUS)
    return PLUS;
  printf("Insira o valor do débito: ");
}

