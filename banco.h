#define BANCO_H
#define TOTAL 1000
#define MAX_CLIENTES 1000


typedef struct{
  char nome[50];
  long cpf[12];
  int conta[10];
  char senha[20];
  float saldo;
  float operacoes[MAX_OPERACOES];
  int pos;
  
}

typedef enum ERROS{MAX_CLIENTES, OK, SENHA_INVALIDA, CPF_INVALIDO, NOME_INVALIDO}

enum ERROS novo(Operacao operacoes[], int *pos); 

enum ERROS apaga(Operacao operacoes[], int *pos);

enum ERROS listar(Operacao operacoes[], int *pos);