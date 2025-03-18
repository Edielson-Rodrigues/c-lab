#include "strategies/strategies.c"

RedBlackTree *createNewNode(RedBlackTree *root, int value);
void insert(RedBlackTree **root, int value);
void changeParentsColors(RedBlackTree *newNode);
void simpleRotationLeft(RedBlackTree *newNode);
void simpleRotationRight(RedBlackTree *newNode);
void doubleRotationLeft(RedBlackTree *newNode);
void doubleRotationRight(RedBlackTree *newNode);
void deleteNode(RedBlackTree **tree, int value);
RedBlackTree *findNode(RedBlackTree *tree, int value);
RedBlackTree *treeMinimum(RedBlackTree *node);
void deleteFixUp(RedBlackTree **tree, RedBlackTree *node, RedBlackTree *parent);