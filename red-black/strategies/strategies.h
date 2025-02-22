#include "stdlib.h"
#include "../enums.h"

enum InsertStrategy {
  INSERT_IN_ROOT = 0,
  INSERT_SUCH_AS_LEFT_SON_OF_ROOT = 1,
  INSERT_SUCH_AS_RIGHT_SON_OF_ROOT = 3,
  INSERT_SUCH_AS_LEFT_SON_OF_BLACK_NODE = 4,
  INSERT_SUCH_AS_RIGHT_SON_OF_BLACK_NODE = 5,
  INSERT_SUCH_AS_LEFT_SON_OF_RED_NODE = 6,
  INSERT_SUCH_AS_RIGHT_SON_OF_RED_NODE = 7
};

enum BalanceStrategy {
  BALANCE_BY_PARENTS_COLORS = 0,
  BALANCE_BY_SIMPLE_ROTATION_LEFT = 1,
  BALANCE_BY_SIMPLE_ROTATION_RIGHT = 2,
  BALANCE_BY_DOUBLE_ROTATION_LEFT = 3,
  BALANCE_BY_DOUBLE_ROTATION_RIGHT= 4,
  BALANCE_IS_NOT_NECESSARY = 5
};

RedBlackTree* getRoot(RedBlackTree* tree, int value);
enum Position getPosition(RedBlackTree* root, int value);
enum InsertStrategy getInsertStrategy(RedBlackTree* root, int value);
enum BalanceStrategy getBalanceStrategy(RedBlackTree* root, enum InsertStrategy insertStrategy, int value);