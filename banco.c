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


ERROS listar(Operacao operacoes[], int *pos) {
    for (int i = 0; i < cliente; ++i) {
    printf("Nome: %s\nCPF: %s\nTipo de Conta: %s\nSaldo: %.2f\n\n",
    clientes[i].nome,
    clientes[i].cpf,
    clientes[i].tipoConta == COMUM ? "Comum" : "Plus",
    clientes[i].saldo);
}
    return OK;
}


ERROS debito(Operacao operacoes[], int *pos) {
    char cpf[12];
    char senha[20];
    double valor;

    printf("CPF: ");
    scanf("%s", cpf);
    
    printf("Senha: ");
    scanf("%s", senha);
    
    printf("Valor: ");
    scanf("%lf", &valor);

    for (int i = 0; i < cliente; ++i) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            double taxa = clientes[i].tipoConta == COMUM ? 0.05 : 0.03;
            double valorComTaxa = valor + (valor * taxa);
            double saldoNegativoPermitido = clientes[i].tipoConta == COMUM ? -1000.0 : -5000.0;

        if (clientes[i].saldo - valorComTaxa >= saldoNegativoPermitido) {
            clientes[i].saldo -= valorComTaxa;

    Operacao operacao;
    snprintf(operacao.descricao, sizeof(operacao.descricao), "Debito de %.2f (taxa: %.2f%%)", valor, taxa * 100);
            
    operacao.valor = -valorComTaxa;
    clientes[i].operacoes[clientes[i].operacao++] = operacao;
                  
    return OK;
            
} else {
            
    return ERRO_DESCONHECIDO;
}    
    }
}

    return SENHA_INVALIDA;
}

ERROS deposito(Operacao operacoes[], int *pos) {
    char cpf[12];
    double valor;

    printf("CPF: ");
    scanf("%s", cpf);
    
    printf("Valor: ");
    scanf("%lf", &valor);

    for (int i = 0; i < cliente; ++i) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
        clientes[i].saldo += valor;

    Operacao operacao;
    snprintf(operacao.descricao, sizeof(operacao.descricao), "Deposito de %.2f", valor);
            
    operacao.valor = valor;
    clientes[i].operacoes[clientes[i].operacao++] = operacao;
              
    return OK;
}
}

    return CPF_INVALIDO;
}


ERROS extrato(Operacao operacoes[], int *pos) {
    char cpf[12];
    char senha[20];

    printf("CPF: ");
    scanf("%s", cpf);
    
    printf("Senha: ");
    scanf("%s", senha);

    for (int i = 0; i < cliente; ++i) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
        char filename[100];
        snprintf(filename, sizeof(filename), "%s_extrato.txt", cpf);
        FILE *file = fopen(filename, "w");

        if (file) {
            fprintf(file, "Extrato de %s (CPF: %s)\n\n", clientes[i].nome, clientes[i].cpf);
    for (int j = 0; j < clientes[i].operacao; ++j) {
        fprintf(file, "%s: %.2f\n", clientes[i].operacoes[j].descricao, clientes[i].operacoes[j].valor);
}
        fclose(file);
    return OK;
} else {
    return ERRO_DESCONHECIDO;
}
    }
        }
    return SENHA_INVALIDA;
}


