#include "stdlib.h"
#include "../enums.h"

typedef enum InsertStrategy
{
  INSERT_IN_ROOT = 0,
  INSERT_SUCH_AS_LEFT_SON_OF_ROOT = 1,
  INSERT_SUCH_AS_RIGHT_SON_OF_ROOT = 3,
  INSERT_SUCH_AS_LEFT_SON_OF_BLACK_NODE = 4,
  INSERT_SUCH_AS_RIGHT_SON_OF_BLACK_NODE = 5,
  INSERT_SUCH_AS_LEFT_SON_OF_RED_NODE = 6,
  INSERT_SUCH_AS_RIGHT_SON_OF_RED_NODE = 7
} InsertStrategy;

typedef enum BalanceStrategy
{
  BALANCE_BY_PARENTS_COLORS = 0,
  BALANCE_BY_SIMPLE_ROTATION_LEFT = 1,
  BALANCE_BY_SIMPLE_ROTATION_RIGHT = 2,
  BALANCE_BY_DOUBLE_ROTATION_LEFT = 3,
  BALANCE_BY_DOUBLE_ROTATION_RIGHT = 4,
  BALANCE_IS_NOT_NECESSARY = 5
} BalanceStrategy;

// Enumeração para as estratégias de remoção
typedef enum DeleteStrategy
{
  DELETE_LEAF,        // Nó é folha (sem filhos)
  DELETE_ONE_CHILD,   // Nó possui apenas um filho
  DELETE_TWO_CHILDREN // Nó possui dois filhos
} DeleteStrategy;

// Enumeração para as estratégias de balanceamento após remoção
typedef enum DeleteBalanceStrategy
{
  DELETE_BALANCE_NONE,         // Não necessita balanceamento
  DELETE_BALANCE_SIMPLE_LEFT,  // Rotação simples à esquerda
  DELETE_BALANCE_SIMPLE_RIGHT, // Rotação simples à direita
  DELETE_BALANCE_DOUBLE_LEFT,  // Rotação dupla à esquerda
  DELETE_BALANCE_DOUBLE_RIGHT  // Rotação dupla à direita
} DeleteBalanceStrategy;

RedBlackTree *getRoot(RedBlackTree *tree, int value);
Position getPosition(RedBlackTree *root, int value);
InsertStrategy getInsertStrategy(RedBlackTree *root, int value);
BalanceStrategy getBalanceStrategy(RedBlackTree *root, InsertStrategy insertStrategy, int value);