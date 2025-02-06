typedef struct BinaryTree {
  int value;
  struct BinaryTree* left;
  struct BinaryTree* right;
} BinaryTree;

BinaryTree* insert(BinaryTree* tree, int value);
void preOrder(BinaryTree* tree);
void inOrder(BinaryTree* tree);
void posOrder(BinaryTree* tree);
void reverse(BinaryTree* tree);
int height(BinaryTree* tree);
int mulchQuantity(BinaryTree* tree);
int exists(BinaryTree* tree, int value);
void printWay(BinaryTree* tree, int value, int init);
BinaryTree* delete(BinaryTree* tree, int value);
BinaryTree* findMin(BinaryTree* tree);