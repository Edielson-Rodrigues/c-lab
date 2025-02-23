#include "rb.h"

RedBlackTree* createNewNode(RedBlackTree* root, int value) {
  RedBlackTree* newNode = (RedBlackTree*) malloc(sizeof(RedBlackTree));

  if (newNode == NULL) {
    return NULL;
  }

  newNode->value = value;
  newNode->father = root;
  newNode->color = root != NULL ? RED : BLACK;
  newNode->left = NULL;
  newNode->right = NULL;
  
  return newNode;
}

void insert(RedBlackTree** tree, int value) {
  RedBlackTree* root = getRoot(*tree, value);
  InsertStrategy insertStrategy = getInsertStrategy(root, value);

  RedBlackTree* newNode = createNewNode(root, value);

  switch (insertStrategy)
  {
    case INSERT_IN_ROOT:
      *tree = newNode;
      
      break;
    case INSERT_SUCH_AS_LEFT_SON_OF_ROOT:
    case INSERT_SUCH_AS_LEFT_SON_OF_BLACK_NODE:
      root->left = newNode;
      newNode->father = root;
      
      break;
    case INSERT_SUCH_AS_RIGHT_SON_OF_ROOT:
    case INSERT_SUCH_AS_RIGHT_SON_OF_BLACK_NODE:
      root->right = newNode;
      newNode->father = root;

      break;
    case INSERT_SUCH_AS_LEFT_SON_OF_RED_NODE:
    case INSERT_SUCH_AS_RIGHT_SON_OF_RED_NODE:
      BalanceStrategy balanceStrategy = getBalanceStrategy(root, insertStrategy, newNode->value);
      
      *(insertStrategy == INSERT_SUCH_AS_LEFT_SON_OF_RED_NODE ? &root->left : &root->right) = newNode;
      newNode->father = root;    
      
      int rootIsAffect = balanceStrategy != BALANCE_BY_PARENTS_COLORS && root->father->father == NULL;

      switch (balanceStrategy)
      {
        case BALANCE_BY_PARENTS_COLORS:
          changeParentsColors(newNode);
          break;
        case BALANCE_BY_SIMPLE_ROTATION_LEFT:
          if (rootIsAffect) *tree = root;
          simpleRotationLeft(newNode);
          break;
        case BALANCE_BY_SIMPLE_ROTATION_RIGHT:
          if (rootIsAffect) *tree = root;
          simpleRotationRight(newNode);
          break;
        case BALANCE_BY_DOUBLE_ROTATION_LEFT:
          if (rootIsAffect) *tree = newNode; 
          doubleRotationLeft(newNode);
          break;
        case BALANCE_BY_DOUBLE_ROTATION_RIGHT:
          if (rootIsAffect) *tree = newNode;
          doubleRotationRight(newNode);
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

void changeParentsColors(RedBlackTree* newNode) {
  RedBlackTree* fatherNode = newNode->father;
  RedBlackTree* grandFatherNode = fatherNode->father;

  grandFatherNode->left->color = grandFatherNode->color;
  grandFatherNode->right->color = grandFatherNode->color;

  grandFatherNode->color = grandFatherNode->father != NULL ? RED : BLACK;
}

void simpleRotationLeft(RedBlackTree* newNode) {
  RedBlackTree* father = newNode->father;
  RedBlackTree* grandFather = father->father;

  father->color = BLACK;
  father->left = grandFather;
  father->father = grandFather->father;  

  grandFather->color = RED;
  grandFather->father = father;
  grandFather->right = NULL;

  RedBlackTree* newGrandFather = father->father;
  if (newGrandFather != NULL) {
    Position newFatherPosition = getPosition(newGrandFather, father->value);
    *(newFatherPosition == LEFT ? &newGrandFather->left : &newGrandFather->right) = father;
  }
}

void simpleRotationRight(RedBlackTree* newNode) {
  RedBlackTree* father = newNode->father;
  RedBlackTree* grandFather = father->father;

  father->color = BLACK;
  father->right = grandFather;
  father->father = grandFather->father;

  grandFather->color = RED;
  grandFather->father = father;
  grandFather->left = NULL;

  RedBlackTree* newGrandFather = father->father;
  if (newGrandFather != NULL) {
    Position newFatherPosition = getPosition(newGrandFather, father->value);
    *(newFatherPosition == LEFT ? &newGrandFather->left : &newGrandFather->right) = father;
  }
}

void doubleRotationLeft(RedBlackTree* newNode) {
  RedBlackTree* father = newNode->father;
  RedBlackTree* grandFather = father->father;

  newNode->father = grandFather; 
  newNode->right = father;

  father->father = newNode;
  father->right = NULL;
  grandFather->right = newNode;

  simpleRotationLeft(newNode->right);
}

void doubleRotationRight(RedBlackTree* newNode) {
  RedBlackTree* father = newNode->father;
  RedBlackTree* grandFather = father->father;

  newNode->father = grandFather;
  newNode->left = father;
  
  father->father = newNode;
  father->left = NULL;
  grandFather->left = newNode;

  simpleRotationRight(newNode->left);
}