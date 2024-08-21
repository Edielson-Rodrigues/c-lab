#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  char* name;
  int age;
  struct Node* next;
} Node;

typedef struct Queue {
  struct Node* person; 
  int size;
  struct Node* last;
} Queue;

Queue* initQueue();
Node* insert(Queue* queue, char* name, int age);
int dequeue(Queue* queue);
void print(Queue* Queue);
char* readName();

Queue* initQueue() {
  Queue* newQueue = (Queue *) malloc(sizeof(Queue));
  struct Node* firstNode = (Node *) malloc(sizeof(Node));
  firstNode = NULL;
  newQueue->size = 0;
  newQueue->person = firstNode;
  newQueue->last = firstNode;
  
  return newQueue;
}

Node* insert(Queue* queue, char* name, int age) {
  Node* newNode = (Node *) malloc(sizeof(Node));
  newNode->name = (char *) malloc(sizeof(char));
  strcpy(newNode->name, name);
  newNode->age = age;
  newNode->next = NULL;

  if (queue->size == 0) {
    queue->person = newNode;
    queue->size++;
  } else {
    Node* current = queue->person;
    while(1) {
      if (current->next == NULL) {
        current->next = newNode;
        queue->size++;
        break;
      }
      current = current->next;
    } 
  }

  return newNode;
}

/**
 * returns 1 for success and 0 for failed
 */
int dequeue(Queue* queue) {
  if (queue->size == 0) {
    return 0;
  }
  Node* newFirstPerson = queue->person->next;
  free(queue->person);
  queue->person = newFirstPerson;
  queue->size--;
  return 1;
}

void print(Queue* queue) {
  if (queue->size == 0) {
    printf("Queue empty.\n");
  }

  Node* currentNode = queue->person;

  while(currentNode != NULL) {
    printf("Name: %s", currentNode->name);
    printf("Age: %d\n", currentNode->age);
    currentNode = currentNode->next;
  }
}

char* readName() {
  char* buffer = NULL;
  size_t bufferSize = 0;

  printf("Enter a name: ");
  getline(&buffer, &bufferSize, stdin);

  return buffer;
}
