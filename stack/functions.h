#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
  char* name;
  int age;
  struct Node* next;
  struct Node* previous;
} Node;

typedef struct Stack {
  Node* start;
  Node* end;
  int size;
} Stack;

Stack* initStack();
Node* insert(Stack* stack, char* name, int age);
int unstack(Stack* stack);
void print(Stack* stack);
char* readName();

Stack* initStack() {
  Stack* newStack = (Stack*) malloc(sizeof(Stack));
  newStack->size = 0;
  newStack->start = NULL; 
  
  return newStack;
}

Node* insert(Stack* stack, char* name, int age) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->name = (char*) malloc(sizeof(char));
  strcpy(newNode->name, name);
  newNode->age = age;
  newNode->next = NULL;

  if (stack->size == 0) {
    newNode->previous = NULL;
    stack->start = newNode;
    stack->end = newNode;
  } else {
    newNode->previous = stack->end;
    stack->end->next = newNode;
    stack->end = newNode;
  }

  stack->size++;
}

int unstack(Stack* stack) {
  if (stack->size == 0) {
    printf("Stack is empty");
    return 0;
  } else if (stack->size == 1) {
    free(stack->end);
    stack->start = NULL;
    stack->end = NULL;
  } else {
    Node* newEnd = stack->end->previous;
    newEnd->next = NULL;
    free(stack->end);
    stack->end = newEnd;
  }

  stack->size--;
  return 1;
}

void print(Stack* stack) {
  if (stack->size == 0) {
    printf("Stack is empty");
  }

  Node* current = stack->end;
  while (current != NULL) {
    printf("\n");
    printf("Name: %s", current->name);
    printf("Age: %d", current->age);

    current = current->previous;
  }

  printf("\n");
}

char* readName() {
  char* buffer = NULL;
  size_t bufferSize = 0;

  printf("Enter a name: ");
  getline(&buffer, &bufferSize, stdin);

  return buffer;
}
