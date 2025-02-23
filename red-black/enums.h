typedef enum Color {
  BLACK = 0,
  RED = 1
} Color;

typedef enum Position {
  LEFT = 0,
  RIGHT = 1
} Position;

typedef struct RedBlackTree {
  int value;
  Color color;
  struct RedBlackTree* left;
  struct RedBlackTree* right;
  struct RedBlackTree* father;
} RedBlackTree;
