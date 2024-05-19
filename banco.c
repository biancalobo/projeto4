#include <string.h>
#include "banco.h"

Cliente clientes[MAX_CLIENTES];
int cliente = 0;

ERROS novo(Operacao operacoes[], int *pos) {
    if (cliente >= MAX_CLIENTES) {
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
    clientes[cliente++] = cliente;

    return OK;
}


ERROS apaga(Operacao operacoes[], int *pos) {
    char cpf[12];
    printf("CPF do cliente a ser removido: ");
    scanf("%s", cpf);

    for (int i = 0; i < cliente; ++i) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
    for (int j = i; j < cliente - 1; ++j) {
        clientes[j] = clientes[j + 1];
}
    --cliente;
return OK;
    }
}
return CPF_INVALIDO;
    
}
