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
  printf("-------------------------\n");
  printf("     Menu de opções\n");
  printf("-------------------------\n");
  printf("[1] - Venda de passagem\n");
  printf("[2] - Mostrar mapa de ocupação\n");
  printf("[3] - Encerrar\n");
  printf("Selecione uma opção: ");
}

void venderPassagem(int poltronasCorredor[24], int poltronasJanela[24]) {
  int opcao, poltrona, indicePoltrona;

  limpar();

  while (true) {
    // Solicita a opção enquanto o usuário não digitar uma opção válida
    printf("Desejam sentar no corredor ou na janela?\n");
    printf("[1] - Corredor\n");
    printf("[2] - Janela\n");
    printf("Selecione uma opção: ");
    scanf("%d", &opcao);

    if (opcao != 1 && opcao != 2) {
      printf("\nOpção inválida.\n");
      continue;
    }

    break;
  }

  while (true) {
    // Solicita a poltrona enquanto o usuário não digitar uma poltrona válida
    printf("\nDigite o número da poltrona: ");
    scanf("%d", &poltrona);

    if (poltrona < 1 || poltrona > 24) {
      printf("\nPoltrona inválida.\n");
      continue;
    }

    break;
  }

  indicePoltrona = poltrona - 1;

  if (opcao == 1) {
    if (poltronasCorredor[indicePoltrona] == 1) {
      printf("\nPoltrona já ocupada.\n");
    } else {
      poltronasCorredor[indicePoltrona] = 1;
      printf("\nVenda efetivada com sucesso.\n");
    }
  } else {
    if (poltronasJanela[indicePoltrona] == 1) {
      printf("\nPoltrona já ocupada.\n");
    } else {
      poltronasJanela[indicePoltrona] = 1;
      printf("\nVenda efetivada com sucesso.\n");
    }
  }
}

void mostrarMapaOcupacao(int poltronasCorredor[24], int poltronasJanela[24]) {
  limpar();

  printf("-------------------------------------\n");
  printf("          Mapa de ocupação\n");
  printf("-------------------------------------\n");

  printf("Corredor:              ");
  printf("Janela:        \n");
  for (int i = 0; i < 24; i++) {
    if (poltronasCorredor[i] == 1) {
      printf("%2d - Ocupada", i + 1);
    } else {
      printf("%2d - Livre  ", i + 1);
    }
    if (poltronasJanela[i] == 1) {
      printf("%14d - Ocupada\n", i + 1);
    } else {
      printf("%14d - Livre\n", i + 1);
    }
  }

  printf("\n\n");
}

int main() {
  int poltronasCorredor[24], poltronasJanela[24];
  int opcao;

  for (int i = 0; i < 24; i++) { // Inicializa as poltronas como vazias
    poltronasCorredor[i] = 0;
    poltronasJanela[i] = 0;
  }

  while (true) {
    mostrarMenu();
    scanf("%d", &opcao);

    if (opcao == 1) {
      venderPassagem(poltronasCorredor, poltronasJanela);
    } else if (opcao == 2) {
      mostrarMapaOcupacao(poltronasCorredor, poltronasJanela);
    } else if (opcao == 3) {
      printf("Encerrando o programa...\n");
      break;
    } else {
      printf("\nOpção inválida.\n\n");
    }
  }

  return 0;
}
