#include "bst.c"
#include "stdlib.h"
#include "stdio.h"

int main() {
    BinaryTree* tree = NULL;
    
    // ==============================
    // Teste 1: Inserção na Árvore
    // ==============================
    tree = insert(tree, 50);
    tree = insert(tree, 30);
    tree = insert(tree, 70);
    tree = insert(tree, 20);
    tree = insert(tree, 40);
    tree = insert(tree, 60);
    tree = insert(tree, 80);
    
    printf("Pré-ordem esperada: [50][30][20][40][70][60][80]\nObtido: ");
    preOrder(tree);
    printf("\n");
    
    printf("Em ordem esperada: [20][30][40][50][60][70][80]\nObtido: ");
    inOrder(tree);
    printf("\n");
    
    printf("Pós-ordem esperada: [20][40][30][60][80][70][50]\nObtido: ");
    posOrder(tree);
    printf("\n");
    
    printf("Reverso esperado: [80][70][60][50][40][30][20]\nObtido: ");
    reverse(tree);
    printf("\n");
    
    // ==============================
    // Teste 2: Altura da Árvore
    // ==============================
    printf("Altura esperada: 3\nObtida: %d\n", height(tree));
    
    // ==============================
    // Teste 3: Verificação de Existência
    // ==============================
    printf("Existe 40? Esperado: 1 | Obtido: %d\n", exists(tree, 40));
    printf("Existe 90? Esperado: 0 | Obtido: %d\n", exists(tree, 90));
    
    // ==============================
    // Teste 4: Impressão do Caminho
    // ==============================
    printf("Caminho para 60: Esperado: [50][70][60]\nObtido: ");
    printWay(tree, 60, 1);
    printf("\n");
    
    // ==============================
    // Teste 5: Remoção de Elementos
    // ==============================
    tree = delete(tree, 20); // Folha
    tree = delete(tree, 30); // Nó com um filho
    tree = delete(tree, 50); // Nó com dois filhos
    
    printf("Árvore após remoções (em ordem esperada: [40][60][70][80])\nObtido: ");
    inOrder(tree);
    printf("\n");
    
    // ==============================
    // Teste 6: Quantidade de Folhas
    // ==============================
    printf("Quantidade de folhas esperada: 2\nObtida: %d\n", mulchQuantity(tree));
    
    return 0;
}
