#include <stdio.h>
#include "banco.h"

int main(void) {
  carregarDados();

  funcao fs[] = {novo, apaga, listar, debito, deposito, extrato, transferencia, sair};

  Operacao operacoes[TOTAL];
  int pos = 0;

int opcao;
  do{
  printf("\nMenu Principal\n");
  printf("1 - Novo cliente\n");
  printf("2 - Apaga cliente\n");
  printf("3 - Listar clientes\n");
  printf("4 - Débito\n");
  printf("5 - Depósito\n");
  printf("6 - Extrato\n");
  printf("7 - Transferência entre contas\n");
  printf("0 - Sair\n");
      
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);

  opcao--;
  if (opcao > 7 || opcao < 0) {
    printf("Opção inválida!\n");
  } else if (opcao >= 0) {
    ERROS erro = fs[opcao](operacoes, &pos);
  if (erro != OK) {
    printf("Erro ao executar a operação %d!\n", opcao + 1);
  }
    
}
    
} while (opcao >= 0);
  ERROS erro_salvar = fs[7](operacoes, &pos);
  if (erro_salvar != OK) {
    printf("Erro ao salvar as operações %d!\n", erro_salvar);
}
return 0;
}
