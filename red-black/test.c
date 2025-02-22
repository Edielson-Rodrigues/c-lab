#include "rb.c"
#include "stdio.h"

int main() {
  RedBlackTree* tree = NULL;

  // ==============================
  // Teste 1: Inserção simples (Apenas coloração)
  // ==============================
  insert(&tree, 10);
  insert(&tree, 20);
  insert(&tree, 30);  // Deve disparar rotação simples à esquerda

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
  insert(&tree, 20);  // Deve disparar rotação dupla Esquerda-Direita

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
  insert(&tree, 70);  // Deve apenas trocar cores, sem rotação

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
  insert(&tree, 10);  // Deve disparar rotação simples à direita

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
  insert(&tree, 20);  // Deve disparar rotação dupla Direita-Esquerda

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
  insert(&tree, 95);  // Sequência para forçar balanceamento

  printf("\nTeste 6: Inserção múltipla com balanceamento completo\n");
  printf("Esperado: Raiz preta\n");
  printf("Obtido: Raiz %s\n", tree->color == BLACK ? "Preta" : "Vermelha");

  return 0;
}
