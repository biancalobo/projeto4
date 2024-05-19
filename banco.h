#ifndef BANCO_H
#define BANCO_H

#include <stdio.h>
#include <stdlib.h>

#define TOTAL 1000
#define MAX_CLIENTES 1000
#define MAX_OPERACOES 100

typedef enum {
    OK,
    MAX_CLIENTES_ERRO,
    SENHA_INVALIDA,
    CPF_INVALIDO,
    NOME_INVALIDO,
    ERRO_DESCONHECIDO
} ERROS;

typedef enum {
    COMUM,
    PLUS
} tipoConta;

typedef struct {
    char descricao[100];
    double valor;
} Operacao;

typedef struct {
    char nome[50];
    char cpf[12];
    tipoConta tipoConta;
    char senha[20];
    float saldo;
    Operacao operacoes[MAX_OPERACOES];
    int operacao;
} Cliente;

typedef ERROS (*funcao)(Operacao operacoes[], int *pos);

ERROS novo(Operacao operacoes[], int *pos);
ERROS apaga(Operacao operacoes[], int *pos);
ERROS listar(Operacao operacoes[], int *pos);
ERROS debito(Operacao operacoes[], int *pos);
ERROS deposito(Operacao operacoes[], int *pos);
ERROS extrato(Operacao operacoes[], int *pos);
ERROS transferencia(Operacao operacoes[], int *pos);
ERROS sair(Operacao operacoes[], int *pos);

void carregarDados();

#endif 
