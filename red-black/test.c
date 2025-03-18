#include "rb.c"
#include "stdio.h"

// Função auxiliar para exibir a árvore em ordem (InOrder)
void printInOrder(RedBlackTree* tree) {
    if (tree == NULL) return;
    printInOrder(tree->left);
    printf("%d(%c) ", tree->value, tree->color == RED ? 'R' : 'B');
    printInOrder(tree->right);
}

int main()
{
  RedBlackTree *tree = NULL;

  // ==============================
  // Teste 1: Inserção simples (Apenas coloração)
  // ==============================
  insert(&tree, 10);
  insert(&tree, 20);
  insert(&tree, 30); // Deve disparar rotação simples à esquerda

  printf("Teste 1: Inserção com rotação simples à esquerda\n");
  printf("Esperado: [20 - B] | Obtido: [%d - %c]\n", tree->value, tree->color == RED ? 'R' : 'B');
  printf("Esperado: [10 - R] | Obtido: [%d - %c]\n", tree->left->value, tree->left->color == RED ? 'R' : 'B');
  printf("Esperado: [30 - R] | Obtido: [%d - %c]\n", tree->right->value, tree->right->color == RED ? 'R' : 'B');

  // ==============================
  // Teste 2: Inserção com rotação dupla (Esquerda-Direita)
  // ==============================
  tree = NULL;
  insert(&tree, 30);
  insert(&tree, 10);
  insert(&tree, 20); // Deve disparar rotação dupla Esquerda-Direita

  printf("\nTeste 2: Inserção com rotação dupla Esquerda-Direita\n");
  printf("Esperado: [20 - B] | Obtido: [%d - %c]\n", tree->value, tree->color == RED ? 'R' : 'B');
  printf("Esperado: [10 - R] | Obtido: [%d - %c]\n", tree->left->value, tree->left->color == RED ? 'R' : 'B');
  printf("Esperado: [30 - R] | Obtido: [%d - %c]\n", tree->right->value, tree->right->color == RED ? 'R' : 'B');

  // ==============================
  // Teste 3: Inserção sem rotação, apenas troca de cores
  // ==============================
  tree = NULL;
  insert(&tree, 40);
  insert(&tree, 20);
  insert(&tree, 60);
  insert(&tree, 10);
  insert(&tree, 30);
  insert(&tree, 50);
  insert(&tree, 70); // Deve apenas trocar cores, sem rotação

  printf("\nTeste 3: Inserção apenas trocando cores (sem rotação)\n");
  printf("Esperado: [40 - B] | Obtido: [%d - %c]\n", tree->value, tree->color == RED ? 'R' : 'B');
  printf("Esperado: [20 - B] | Obtido: [%d - %c]\n", tree->left->value, tree->left->color == RED ? 'R' : 'B');
  printf("Esperado: [60 - B] | Obtido: [%d - %c]\n", tree->right->value, tree->right->color == RED ? 'R' : 'B');
  printf("Esperado: [10 - R] | Obtido: [%d - %c]\n", tree->left->left->value, tree->left->left->color == RED ? 'R' : 'B');
  printf("Esperado: [30 - R] | Obtido: [%d - %c]\n", tree->left->right->value, tree->left->right->color == RED ? 'R' : 'B');
  printf("Esperado: [50 - R] | Obtido: [%d - %c]\n", tree->right->left->value, tree->right->left->color == RED ? 'R' : 'B');
  printf("Esperado: [70 - R] | Obtido: [%d - %c]\n", tree->right->right->value, tree->right->right->color == RED ? 'R' : 'B');

  // ==============================
  // Teste 4: Inserção com rotação simples à direita
  // ==============================
  tree = NULL;
  insert(&tree, 30);
  insert(&tree, 20);
  insert(&tree, 10); // Deve disparar rotação simples à direita

  printf("\nTeste 4: Inserção com rotação simples à direita\n");
  printf("Esperado: [20 - B] | Obtido: [%d - %c]\n", tree->value, tree->color == RED ? 'R' : 'B');
  printf("Esperado: [10 - R] | Obtido: [%d - %c]\n", tree->left->value, tree->left->color == RED ? 'R' : 'B');
  printf("Esperado: [30 - R] | Obtido: [%d - %c]\n", tree->right->value, tree->right->color == RED ? 'R' : 'B');

  // ==============================
  // Teste 5: Inserção com rotação dupla (Direita-Esquerda)
  // ==============================
  tree = NULL;
  insert(&tree, 10);
  insert(&tree, 30);
  insert(&tree, 20); // Deve disparar rotação dupla Direita-Esquerda

  printf("\nTeste 5: Inserção com rotação dupla Direita-Esquerda\n");
  printf("Esperado: [20 - B] | Obtido: [%d - %c]\n", tree->value, tree->color == RED ? 'R' : 'B');
  printf("Esperado: [10 - R] | Obtido: [%d - %c]\n", tree->left->value, tree->left->color == RED ? 'R' : 'B');
  printf("Esperado: [30 - R] | Obtido: [%d - %c]\n", tree->right->value, tree->right->color == RED ? 'R' : 'B');

  // ==============================
  // Teste 6: Inserção múltipla com balanceamento completo
  // ==============================
  tree = NULL;
  insert(&tree, 50);
  insert(&tree, 25);
  insert(&tree, 75);
  insert(&tree, 10);
  insert(&tree, 40);
  insert(&tree, 60);
  insert(&tree, 90);
  insert(&tree, 5);
  insert(&tree, 15);
  insert(&tree, 30);
  insert(&tree, 45);
  insert(&tree, 55);
  insert(&tree, 65);
  insert(&tree, 80);
  insert(&tree, 95); // Sequência para forçar balanceamento

  printf("\nTeste 6: Inserção múltipla com balanceamento completo\n");
  printf("Esperado: Raiz preta\n");
  printf("Obtido: Raiz %s\n", tree->color == BLACK ? "Preta" : "Vermelha");

  // ==============================
  // Testes de Remoção
  // ==============================

  // Teste 7: Remoção de nó folha
  // Cria uma árvore simples e remove um nó folha
  tree = NULL;
  insert(&tree, 50);
  insert(&tree, 25);
  insert(&tree, 75);
  // Árvore: raiz 50, filho esquerdo 25, filho direito 75
  deleteNode(&tree, 25); // Remove o nó folha (25)

  printf("\nTeste 7: Remoção de nó folha\n");
  printf("Esperado: Nó 25 removido\n");
  if (tree->left == NULL)
      printf("Obtido: Nó 25 removido com sucesso\n");
  else
      printf("Obtido: Falha na remoção do nó 25\n");
  printf("Árvore InOrder: ");
  printInOrder(tree);
  printf("\n");

  // Teste 8: Remoção de nó com um filho
  // Cria uma árvore onde o nó 25 possui apenas um filho
  tree = NULL;
  insert(&tree, 50);
  insert(&tree, 25);
  insert(&tree, 75);
  insert(&tree, 10); // O nó 25 terá um filho (10)
  deleteNode(&tree, 25); // Remove o nó com um filho

  printf("\nTeste 8: Remoção de nó com um filho\n");
  printf("Esperado: Nó 25 removido e 10 promovido como filho de 50\n");
  if (tree->left && tree->left->value == 10)
      printf("Obtido: Remoção e promoção realizadas corretamente\n");
  else
      printf("Obtido: Falha na remoção ou promoção do nó 10\n");
  printf("Árvore InOrder: ");
  printInOrder(tree);
  printf("\n");

  // Teste 9: Remoção de nó com dois filhos
  // Cria uma árvore onde o nó 25 possui dois filhos (10 e 40)
  tree = NULL;
  insert(&tree, 50);
  insert(&tree, 25);
  insert(&tree, 75);
  insert(&tree, 10);
  insert(&tree, 40);
  deleteNode(&tree, 25); // Remove o nó com dois filhos

  printf("\nTeste 9: Remoção de nó com dois filhos\n");
  printf("Esperado: Nó 25 removido e substituído por seu sucessor (10 ou 40)\n");
  if (tree->left && tree->left->value != 25)
      printf("Obtido: Nó 25 removido com sucesso. Novo nó na posição: %d\n", tree->left->value);
  else
      printf("Obtido: Falha na remoção do nó 25\n");
  printf("Árvore InOrder: ");
  printInOrder(tree);
  printf("\n");

  return 0;
}
