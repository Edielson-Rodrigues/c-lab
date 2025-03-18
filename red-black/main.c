#include "rb.c"
#include "stdio.h"

void preOrder(RedBlackTree *tree)
{
  if (tree == NULL)
    return;
  printf("[%d %c]", tree->value, tree->color == RED ? 'R' : 'B');
  preOrder(tree->left);
  preOrder(tree->right);
}

int main()
{
  RedBlackTree *tree = NULL;
  int option, value;

  do
  {
    printf("\n=== ARVORE RUBRO-NEGRA ===\n");
    printf("1. Inserir\n");
    printf("2. Preorder\n");
    printf("3. Remover\n");
    printf("99. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Digite o valor para inserir: ");
      scanf("%d", &value);
      insert(&tree, value);
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
      deleteNode(&tree, value);
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
