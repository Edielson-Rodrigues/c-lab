#include "bst.h"
#include "stdlib.h"
#include "stdio.h"

BinaryTree* insert(BinaryTree* tree, int value) {
  if (tree == NULL) {
    BinaryTree* newTree = (BinaryTree*) malloc(sizeof(BinaryTree));
    newTree->value = value;
    newTree->left = NULL;
    newTree->right = NULL;

    return newTree;
  } else {
    if (value < tree->value) {
      tree->left = insert(tree->left, value);
    } else {
      tree->right = insert(tree->right, value);
    }

    return tree;
  }
}

void preOrder(BinaryTree* tree) {
  if (tree == NULL) {
    return;
  }

  printf("[%d]", tree->value);
  preOrder(tree->left);
  preOrder(tree->right);
}

void inOrder(BinaryTree* tree) {
  if (tree == NULL) {
    return;
  }

  inOrder(tree->left);
  printf("[%d]", tree->value);
  inOrder(tree->right);
}

void posOrder(BinaryTree* tree) {
  if (tree == NULL) {
    return;
  }

  posOrder(tree->left);
  posOrder(tree->right);
  printf("[%d]", tree->value);
}

void reverse(BinaryTree* tree) {
  if (tree == NULL) {
    return;
  }

  reverse(tree->right);
  printf("[%d]", tree->value);
  reverse(tree->left);
}

int mulchQuantity(BinaryTree* tree) {
  if(tree == NULL) {
    return 0;
  } else if (tree->left == NULL && tree->right == NULL) {
    return 1;
  }

  return mulchQuantity(tree->left) + mulchQuantity(tree->right);
}

int height(BinaryTree* tree) {
  if (tree == NULL) {
    return 0;
  }
  
  int heightLeft = height(tree->left);
  int heightRight = height(tree->right);
  return (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

int exists(BinaryTree* tree, int value) {
  if (tree == NULL) {
    return 0;
  }

  if (value < tree->value) {
    return exists(tree->left, value);
  } else if (value > tree->value) {
    return exists(tree->right, value);
  }

  return 1;
}

void printWay(BinaryTree* tree, int value, int init) {
  if (init && !exists(tree, value)) {
    printf("\n");
    return; 
  }

  printf("[%d]", tree->value);

  if (value < tree->value) {
    return printWay(tree->left, value, 0);
  } else if (value > tree->value) {
    return printWay(tree->right, value, 0);
  }

  return;
}

BinaryTree* delete(BinaryTree* tree, int value) {
  if (tree == NULL) {
    return NULL;
  }

  if (value < tree->value) {
    tree->left = delete(tree->left, value);
  } else if (value > tree->value) {
    tree->right = delete(tree->right, value);
  } else {
    if (tree->left == NULL && tree->right == NULL) {
      free(tree);
      return NULL;
    } else if (tree->left != NULL && tree->right == NULL) {
      BinaryTree* auxTree = tree->left;
      free(tree);
      return auxTree;
    } else if (tree->right != NULL && tree->left == NULL) {
      BinaryTree* auxTree = tree->right;
      free(tree);
      return auxTree;
    } else {
      BinaryTree* min = findMin(tree->right);
      tree->value = min->value;
      
      tree->right = delete(tree->right, min->value);

      return tree;
    }
  }

  return tree;
}

BinaryTree* findMin(BinaryTree* tree) {
  if (tree == NULL) {
    return NULL;
  }

  return tree->left != NULL ? findMin(tree->left) : tree;
}
