enum Color {
  BLACK = 0,
  RED = 1
};

enum Position {
  LEFT = 0,
  RIGHT = 1
};

typedef struct RedBlackTree {
  int value;
  enum Color color;
  struct RedBlackTree* left;
  struct RedBlackTree* right;
  struct RedBlackTree* father;
} RedBlackTree;
