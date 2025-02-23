#include "strategies.h"

Position getPosition(RedBlackTree* root, int value) {
  return value < root->value ? LEFT : RIGHT;
}

RedBlackTree* getRoot(RedBlackTree* tree, int value) {
  if (tree == NULL) {
    return tree;
  } else if (tree->left == NULL && tree->right == NULL) {
    return tree;
  } 
  RedBlackTree* currentNode = tree;

  while (1) {
    Position postionToInsert = getPosition(currentNode, value);

    if (postionToInsert == LEFT) {
      if (currentNode->left == NULL) break;
      currentNode = currentNode->left;
    } else if (postionToInsert == RIGHT) {
      if (currentNode->right == NULL) break;
      currentNode = currentNode->right;
    }
  }

  return currentNode;
}

InsertStrategy getInsertStrategy(RedBlackTree* root, int value) {
  if (root == NULL) {
    return INSERT_IN_ROOT;
  }

  Position position = getPosition(root, value);
  RedBlackTree* grandFather = root->father;

  if (grandFather == NULL) {
    return position == LEFT ? INSERT_SUCH_AS_LEFT_SON_OF_ROOT : INSERT_SUCH_AS_RIGHT_SON_OF_ROOT;
  } else if (root->color == BLACK) {
    return position == LEFT ? INSERT_SUCH_AS_LEFT_SON_OF_BLACK_NODE : INSERT_SUCH_AS_RIGHT_SON_OF_BLACK_NODE;
  }

  return position == LEFT ? INSERT_SUCH_AS_LEFT_SON_OF_RED_NODE : INSERT_SUCH_AS_RIGHT_SON_OF_RED_NODE;
}

/**
 * @see strategies (InsertStrategy + BalanceStrategy) 
 * 
 * 1. INSERT_IN_ROOT -> sem strategy
 * 2. INSERT_SUCH_AS_LEFT_SON_OF_ROOT -> sem strategy
 * 3. INSERT_SUCH_AS_RIGHT_SON_OF_ROOT -> sem strategy
 * 4. INSERT_SUCH_AS_SON_OF_BLACK_NODE -> sem strategy
 * 5. INSERT_SUCH_AS_SON_OF_RED_NODE -> (
 *        1. BALANCE_BY_PARENTS_COLORS
 *        2. BALANCE_BY_SIMPLE_ROTATION_LEFT
 *        3. BALANCE_BY_SIMPLE_ROTATION_RIGHT
 *        4. BALANCE_BY_DOUBLE_ROTATION_LEFT
 *        5. BALANCE_BY_DOUBLE_ROTATION_RIGHT
 * 
   )
 */
BalanceStrategy getBalanceStrategy(RedBlackTree* root, InsertStrategy insertStrategy, int value) {
  if (INSERT_SUCH_AS_LEFT_SON_OF_RED_NODE || INSERT_SUCH_AS_RIGHT_SON_OF_RED_NODE) {
    RedBlackTree* nodeGrandFather = root->father;
    
    if (
      nodeGrandFather->left != NULL &&
      nodeGrandFather->right != NULL &&
      nodeGrandFather->left->color == RED &&
      nodeGrandFather->right->color == RED &&
      nodeGrandFather->color == BLACK
    ) {
      return BALANCE_BY_PARENTS_COLORS;
    }
  
    Position fatherPosition = getPosition(nodeGrandFather, root->value);
    Position newRootPostion = insertStrategy == INSERT_SUCH_AS_LEFT_SON_OF_RED_NODE ? LEFT : RIGHT;
  
    if (fatherPosition == LEFT && newRootPostion == LEFT) {
      return BALANCE_BY_SIMPLE_ROTATION_RIGHT;
    } else if (fatherPosition == LEFT && newRootPostion == RIGHT) {
      return BALANCE_BY_DOUBLE_ROTATION_RIGHT;
    } else if (fatherPosition == RIGHT && newRootPostion == RIGHT) {
      return BALANCE_BY_SIMPLE_ROTATION_LEFT;
    } else if (fatherPosition == RIGHT && newRootPostion == LEFT) {
      return BALANCE_BY_DOUBLE_ROTATION_LEFT;
    }
  }

  return BALANCE_IS_NOT_NECESSARY;
}