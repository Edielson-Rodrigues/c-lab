#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#include "avl.c"

int main() {
  AvlTree* tree = NULL;
  int* grow = (int*) malloc(sizeof(int));
  int* decreased = (int*) malloc(sizeof(int));
  int option, value;

  do {
    printf("\n=== MENU AVL ===\n");
    printf("1. Inserir\n");
    printf("2. Preorder\n");
    printf("3. Remover\n");
    printf("99. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Digite o valor para inserir: ");
        scanf("%d", &value);
        tree = insert(tree, value, grow);
        *grow = 0;
        printf("Valor %d inserido.\n", value);
        break;

      case 2:
        printf("Preorder: ");
        preOrder(tree);
        printf("\n");
        break;

      case 3:
        printf("Digite o valor para remover: ");
        scanf("%d", &value);
        tree = delete(tree, value, decreased);
        *decreased = 0;
        printf("Valor %d removido (se existia).\n", value);
        break;

      case 99:
        printf("Saindo do programa...\n");
        break;

      default:
        printf("Opcao invalida! Tente novamente.\n");
    }
  } while (option != 99);

  free(grow);
  free(decreased);

  return 0;
}
