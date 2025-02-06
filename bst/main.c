#include "stdlib.h"
#include "stdio.h"
#include "bst.c"

int main() {
  BinaryTree* tree = NULL;
  int option, value;

  do {
    printf("\n=== MENU ===\n");
    printf("1. Inserir\n");
    printf("2. Preorder\n");
    printf("3. Inorder\n");
    printf("4. Posorder\n");
    printf("5. Reverso\n");
    printf("6. Altura\n");
    printf("7. Quantidade de Folhas\n");
    printf("8. Caminho\n");
    printf("9. Remover\n");
    printf("99. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Digite o valor para inserir: ");
        scanf("%d", &value);
        tree = insert(tree, value);
        printf("Valor %d inserido.\n", value);
        break;

      case 2:
        printf("Preorder: ");
        preOrder(tree);
        printf("\n");
        break;

      case 3:
        printf("Inorder: ");
        inOrder(tree);
        printf("\n");
        break;

      case 4:
        printf("Posorder: ");
        posOrder(tree);
        printf("\n");
        break;

      case 5:
        printf("Reverso: ");
        reverse(tree);
        printf("\n");
        break;

      case 6:
        printf("Altura da arvore: %d\n", height(tree));
        break;

      case 7:
        printf("Quantidade de folhas: %d\n", mulchQuantity(tree));
        break;

      case 8:
        printf("Digite o valor para exibir o caminho: ");
        scanf("%d", &value);
        printf("Caminho até %d: ", value);
        printWay(tree, value, 1);
        break;

      case 9:
        printf("Digite o valor para remover: ");
        scanf("%d", &value);
        tree = delete(tree, value);
        printf("Valor %d removido (se existia).\n", value);
        break;

      case 99:
        printf("Saindo do programa...\n");
        break;

      default:
        printf("Opcao invalida! Tente novamente.\n");
      }
  } while (option != 99);

  return 0;
}
