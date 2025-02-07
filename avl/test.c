#include "avl.c"
#include "stdlib.h"
#include "stdio.h"
#include <math.h>

int main() {
    AvlTree* tree = NULL;
    int* grow = (int*) malloc(sizeof(int));
    int* decreased = (int*) malloc(sizeof(int));

    // ==============================
    // Teste 1: Rotação Simples à Direita
    // ==============================
    tree = insert(tree, 30, grow);
    tree = insert(tree, 20, grow);
    tree = insert(tree, 10, grow);  // Deve disparar rotação simples à direita

    printf("Esperado: [20 - 0] | Obtido: [%d - %d]\n", tree->value, tree->balanceFactor);
    printf("Esperado: [10 - 0] | Obtido: [%d - %d]\n", tree->left->value, tree->left->balanceFactor);
    printf("Esperado: [30 - 0] | Obtido: [%d - %d]\n", tree->right->value, tree->right->balanceFactor);

    // ==============================
    // Teste 2: Rotação Simples à Esquerda
    // ==============================
    tree = NULL;
    tree = insert(tree, 10, grow);
    tree = insert(tree, 20, grow);
    tree = insert(tree, 30, grow);  // Deve disparar rotação simples à esquerda
    *grow = 0;
    
    printf("Esperado: [20 - 0] | Obtido: [%d - %d]\n", tree->value, tree->balanceFactor);
    printf("Esperado: [10 - 0] | Obtido: [%d - %d]\n", tree->left->value, tree->left->balanceFactor);
    printf("Esperado: [30 - 0] | Obtido: [%d - %d]\n", tree->right->value, tree->right->balanceFactor);

    // ==============================
    // Teste 3: Rotação Dupla Direita-Esquerda
    // ==============================
    tree = NULL;
    tree = insert(tree, 10, grow);
    tree = insert(tree, 30, grow);
    tree = insert(tree, 20, grow);  // Deve disparar rotação dupla Direita-Esquerda
    *grow = 0;

    printf("Esperado: [20 - 0] | Obtido: [%d - %d]\n", tree->value, tree->balanceFactor);
    printf("Esperado: [10 - 0] | Obtido: [%d - %d]\n", tree->left->value, tree->left->balanceFactor);
    printf("Esperado: [30 - 0] | Obtido: [%d - %d]\n", tree->right->value, tree->right->balanceFactor);

    // ==============================
    // Teste 4: Rotação Dupla Esquerda-Direita
    // ==============================
    tree = NULL;
    tree = insert(tree, 30, grow);
    tree = insert(tree, 10, grow);
    tree = insert(tree, 20, grow);  // Deve disparar rotação dupla Esquerda-Direita
    *grow = 0;

    printf("Esperado: [20 - 0] | Obtido: [%d - %d]\n", tree->value, tree->balanceFactor);
    printf("Esperado: [10 - 0] | Obtido: [%d - %d]\n", tree->left->value, tree->left->balanceFactor);
    printf("Esperado: [30 - 0] | Obtido: [%d - %d]\n", tree->right->value, tree->right->balanceFactor);

    // ==============================
    // Teste 5: Remoção com Rotação Simples
    // ==============================
    tree = NULL;
    tree = insert(tree, 30, grow);
    tree = insert(tree, 20, grow);
    tree = insert(tree, 10, grow);
    tree = insert(tree, 25, grow);
    tree = insert(tree, 40, grow);
    tree = insert(tree, 35, grow);
    tree = insert(tree, 50, grow);

    tree = delete(tree, 50, decreased); // Deve disparar rotação simples

    *grow = 0;
    printf("Esperado: [30 - 0] | Obtido: [%d - %d]\n", tree->value, tree->balanceFactor);
    printf("Esperado: [20 - 0] | Obtido: [%d - %d]\n", tree->left->value, tree->left->balanceFactor);
    printf("Esperado: [40 - -1] | Obtido: [%d - %d]\n", tree->right->value, tree->right->balanceFactor);

    // ==============================
    // Teste 6: Remoção com Rotação Dupla
    // ==============================
    tree = NULL;
    tree = insert(tree, 40, grow);
    tree = insert(tree, 20, grow);
    tree = insert(tree, 50, grow);
    tree = insert(tree, 10, grow);
    tree = insert(tree, 30, grow);
    tree = insert(tree, 25, grow);
    tree = insert(tree, 35, grow);

    tree = delete(tree, 10, decreased); // Deve disparar rotação dupla

    *grow = 0;
    printf("Esperado: [30 - 0] | Obtido: [%d - %d]\n", tree->value, tree->balanceFactor);
    printf("Esperado: [20 - 0] | Obtido: [%d - %d]\n", tree->left->value, tree->left->balanceFactor);
    printf("Esperado: [40 - 0] | Obtido: [%d - %d]\n", tree->right->value, tree->right->balanceFactor);

    free(grow);
    free(decreased);

    return 0;
}
