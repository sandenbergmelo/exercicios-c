#include <stdbool.h> // Biblioteca para usar o tipo bool
#include <stdio.h>
#include <stdlib.h>

void limpar() {
// Limpa a tela de acordo com o sistema operacional
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void mostrarMenu() {
  printf("O que deseja fazer?\n");
  printf("[1] - Efetuar depósito.\n");
  printf("[2] - Efetuar saque.\n");
  printf("[3] - Consultar ativos.\n");
  printf("[4] - Sair do programa.\n");
  printf("Selecione uma opção: ");
}

// Função que verifica se o código já existe
bool codigoJaDigitado(int codigo, int conta[10]) {
  for (int i = 1; i <= 10; i++) {
    if (codigo == conta[i]) {
      return true;
    }
  }
  return false;
}

void efetuarDeposito(int contas[10], float saldo[10]) {
  int indiceConta = -1, codigoConta;
  float valor;

  limpar();

  printf("-------------------------\n");
  printf("   Efetuar deposito:\n");
  printf("-------------------------\n");

  // Solicita o código da conta
  while (true) {

    printf("Digite o código da conta: ");
    scanf("%d", &codigoConta);
    setbuf(stdin, NULL);

    // Verifica se a conta existe
    for (int i = 1; i <= 10; i++) {
      if (codigoConta == contas[i]) {
        indiceConta = i;
        break;
      }
    }
    if (indiceConta == -1) {
      printf("Conta inexistente.\n");
      continue;
    }
    break;
  }

  printf("Digite o valor a ser depositado: ");
  scanf("%f", &valor);
  setbuf(stdin, NULL);

  saldo[indiceConta] += valor;

  printf("\nDepósito efetuado com sucesso!\n\n");
}

void efetuarSaque(int contas[10], float saldo[10]) {
  int indiceConta = -1, codigoConta;
  float valor;

  limpar();

  printf("-------------------------\n");
  printf("       Efetuar Saque:\n");
  printf("-------------------------\n");

  // Solicita o código da conta
  while (true) {

    printf("Digite o código da conta: ");
    scanf("%d", &codigoConta);
    setbuf(stdin, NULL);

    // Verifica se a conta existe
    for (int i = 1; i <= 10; i++) {
      if (codigoConta == contas[i]) {
        indiceConta = i;
        break;
      }
    }
    if (indiceConta == -1) {
      printf("Conta inexistente.\n");
      continue;
    }
    break;
  }

  // Solicita o valor a ser sacado
  while (true) {
    printf("Digite o valor a ser sacado: ");
    scanf("%f", &valor);
    setbuf(stdin, NULL);

    // Verifica se o valor é maior que o saldo
    if (valor > saldo[indiceConta]) {
      printf("Saldo insuficiente.\n");
      continue;
    }

    break;
  }

  saldo[indiceConta] -= valor;

  printf("\nSaque efetuado com sucesso!\n\n");
}

void consultarAtivos(int contas[10], float saldo[10]) {

  limpar();
  printf("-------------------------\n");
  printf("       Ativos:\n");
  printf("-------------------------\n");

  for (int i = 1; i <= 10; i++) {
    printf("Conta: %d - Saldo: R$%.2f\n", contas[i], saldo[i]);
  }

  // Somatório dos saldos
  float soma = 0;
  for (int i = 1; i <= 10; i++) {
    soma += saldo[i];
  }
  printf("\nTotal de ativos: R$%.2f\n\n", soma);
}

int main() {

  int opcao, codigo, conta[10];
  float saldo[10];

  limpar();

  for (int i = 1; i <= 10; i++) {
    // Solicita o código e verifica se já existe
    while (true) {
      printf("Digite o código do cliente %d: ", i);
      scanf("%d", &codigo);
      setbuf(stdin, NULL);

      // Verifica se o código já foi digitado
      if (codigoJaDigitado(codigo, conta)) {
        printf("Código já existe!\n");
      } else {
        conta[i] = codigo;

        printf("Digite o saldo do cliente %d: ", i);
        scanf("%f", &saldo[i]);
        setbuf(stdin, NULL);
        printf("\n");
        break;
      }
    }
  }

  limpar();

  while (true) {
    mostrarMenu();
    scanf("%d", &opcao);

    if (opcao == 1) {
      efetuarDeposito(conta, saldo);
    } else if (opcao == 2) {
      efetuarSaque(conta, saldo);
    } else if (opcao == 3) {
      consultarAtivos(conta, saldo);
    } else if (opcao == 4) { // Sair do programa
      break;
    } else {
      printf("\nOpção inválida.\n\n");
    }
  }

  printf("Obrigado por utilizar o programa!\n");

  return 0;
}
