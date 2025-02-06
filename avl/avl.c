#include "stdio.h"
#include "stdlib.h"
#include "avl.h"

AvlTree* insert(AvlTree* tree, int value, int* grow) {
  if (tree == NULL) {
    AvlTree* newTree = (AvlTree*) malloc(sizeof(AvlTree));
    newTree->value = value;
    newTree->balanceFactor = 0;
    newTree->left = NULL;
    newTree->right = NULL;

    *grow = 1;

    return newTree;
  } else {
    if (value < tree->value) {
      tree->left = insert(tree->left, value, grow);
      
      if (*grow) {
        switch (tree->balanceFactor) {
          case -1:
            tree->balanceFactor = -2;
            *grow = 0; 
            tree = rotation(tree);            
            break;
          case 0:
            tree->balanceFactor = -1;
            break;
          case 1:
            tree->balanceFactor = 0;
            *grow = 0;
            break;
        }
      }

    } else {
      tree->right = insert(tree->right, value, grow);
      
      if (*grow) {
        switch (tree->balanceFactor) {
          case -1:
            tree->balanceFactor = 0;
            *grow = 0;
            break;
          case 0:
            tree->balanceFactor = 1;
            break;
          case 1:
            tree->balanceFactor = 2;
            *grow = 0;
            tree = rotation(tree);
            break;
        }
      }
    }

    return tree;
  }
}

AvlTree* delete(AvlTree* tree, int value, int* decreased) {
  if (tree == NULL) {
    *decreased = 0;
    return NULL;
  }

  if (value < tree->value) {
    tree->left = delete(tree->left, value, decreased);
    if (*decreased) tree->balanceFactor++;
  } else if (value > tree->value) {
    tree->right = delete(tree->right, value, decreased);
    if (*decreased) tree->balanceFactor--;
  } else {
    if (tree->left == NULL && tree->right == NULL) {
      free(tree);
      *decreased = 1;
      return NULL;
    } else if (tree->left == NULL) {
      AvlTree* auxTree = tree->right;
      free(tree);
      *decreased = 1;
      return auxTree;
    } else if (tree->right == NULL) {
      AvlTree* auxTree = tree->left;
      free(tree);
      *decreased = 1;
      return auxTree;
    } else {
      AvlTree* maxTreeInLeft = findMaxTree(tree->left);
      tree->value = maxTreeInLeft->value;
      tree->left = delete(tree->left, maxTreeInLeft->value, decreased);
      if (*decreased) tree->balanceFactor++;
    }
  }

  if (*decreased) {
    tree = rotation(tree);

    if (tree->balanceFactor == 0) {
      *decreased = 1;
    } else {
      *decreased = 0;
    }
  }

  return tree;
}

AvlTree* rotationLeft(AvlTree* tree) {
  AvlTree* newRoot = tree->right;
  tree->right = newRoot->left;
  newRoot->left = tree;

  tree->balanceFactor = tree->balanceFactor - 1 - valueMax(0, newRoot->balanceFactor);
  newRoot->balanceFactor = newRoot->balanceFactor - 1 + valueMin(0, tree->balanceFactor);

  return newRoot;
}

AvlTree* rotationRight(AvlTree* tree) {
  AvlTree* newRoot = tree->left;
  tree->left = newRoot->right;
  newRoot->right = tree;

  tree->balanceFactor = tree->balanceFactor + 1 - valueMin(0, newRoot->balanceFactor);
  newRoot->balanceFactor = newRoot->balanceFactor + 1 + valueMax(0, tree->balanceFactor);

  return newRoot;
}

AvlTree* doubleRotationLeft(AvlTree* tree) {
  tree->right = rotationRight(tree->right);
  return rotationLeft(tree);
}

AvlTree* doubleRotationRight(AvlTree* tree) {
  tree->left = rotationLeft(tree->left);
  return rotationRight(tree);
}

AvlTree* rotation(AvlTree* tree) {
  if (tree->balanceFactor >= 2) {
    return tree->right->balanceFactor <= -1 ? doubleRotationLeft(tree) : rotationLeft(tree);
  } else if (tree->balanceFactor <= -2) {
     return tree->left->balanceFactor >= 1 ? doubleRotationRight(tree) : rotationRight(tree);
  }

  return tree;
}

AvlTree* findMaxTree(AvlTree* tree) {
  if (tree == NULL) {
    return tree;
  } else if (tree->right != NULL) {
    return findMaxTree(tree->right);
  }

  return tree;
}

void preOrder(AvlTree* tree) {
  if (tree == NULL) {
    return;
  }

  printf("[%d - %d] ", tree->value, tree->balanceFactor);
  preOrder(tree->left);
  preOrder(tree->right);
}

int valueMax(int a, int b) {
  return (a > b) ? a : b;
}

int valueMin(int a, int b) {
  return (a < b) ? a : b;
}
