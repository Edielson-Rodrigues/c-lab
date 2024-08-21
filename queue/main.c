#include <stdio.h>
#include "functions.h"

int main() {
  Queue* queue = initQueue();
  int choice;
  int loop = 1;

  while(loop) {
    printf("--------------------Menu--------------------\n");
    printf("1. Insert\n");
    printf("2. Dequeue\n");
    printf("3. Print\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int c;

    while ((c = getchar()) != EOF && c != '\n');

    switch(choice) {
      case 1:
        char *name = readName();
        int age;
        printf("Digit the age: ");
        scanf("%d", &age);
        insert(queue, name, age);
        break;
      case 2:
        dequeue(queue);
        break;
      case 3:
        print(queue);
        break;
      case 4:
        loop = 0;
        break;
      default:
        printf("Option is invalid.\n");
        break;
    }
  }

  free(queue);

  return 0;
}