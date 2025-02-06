typedef struct AvlTree {
  int value;
  int balanceFactor;
  struct AvlTree* left;
  struct AvlTree* right;
} AvlTree;

AvlTree* insert(AvlTree* tree, int value, int* grow);
AvlTree* delete(AvlTree* tree, int value, int* decreased);
AvlTree* rotationLeft(AvlTree* tree);
AvlTree* rotationRight(AvlTree* tree);
AvlTree* doubleRotationLeft(AvlTree* tree);
AvlTree* doubleRotationRight(AvlTree* tree);
AvlTree* rotation(AvlTree* tree);
AvlTree* findMaxTree(AvlTree* tree);
void preOrder(AvlTree* tree);
int valueMax(int a, int b);
int valueMin(int a, int b);