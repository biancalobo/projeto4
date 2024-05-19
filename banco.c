#include <string.h>
#include "banco.h"

Cliente clientes[MAX_CLIENTES];
int clienteCount = 0;

ERROS novo(Operacao operacoes[], int *pos) {
    if (clienteCount >= MAX_CLIENTES) {
        return MAX_CLIENTES_ERRO;
} Cliente cliente;
    printf("Insira o nome do cliente: ");
    scanf("%s", cliente.nome);
    
    printf("Insira o CPF do cliente: ");
    scanf("%s", cliente.cpf);
    
    printf("Insira uma senha para a conta: ");
    scanf("%s", cliente.senha);
    
    printf("Insira o tipo de conta (0 - Comum, 1 - Plus): ");
    int tipo;
    scanf("%d", &tipo);
    cliente.tipoConta = tipo == 0 ? COMUM : PLUS;
    
    printf("Insira o saldo inicial da conta: ");
    scanf("%f", &cliente.saldo);

    cliente.operacao = 0;
    clientes[clienteCount++] = cliente;

    return OK;
}

