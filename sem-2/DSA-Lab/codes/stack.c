#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int c = 0;

typedef struct stack {
  int a[SIZE];
  int top;
} st;

// typedef struct stack st;

void ces(st *s) {
  s->top = -1;
}

int isoverflow(st *s) {
  if (s->top == SIZE - 1)
    return 1;
  else
    return 0;
}

int isunderflow(st *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

void push(st *s, int e) {
  if (isoverflow(s)) {
    printf("Stack Overflow!\n");
  }
  else {
    s->top++;
    s->a[s->top] = e;
  }
  c++;
}

void pop(st *s) {
  if (isunderflow(s)) {
    printf("Stack Underflow!\n");
  }
  else {
    printf("popped element is %d\n", s->a[s->top]);
    s->top--;
  }
  c--;
}

void printstack(st *s) {
  printf("Current stack : \n");
  for (int i = 0; i < c; i++) {
    printf("%d\n", s->a[i]);
    printf("\n");
  }
}

int main() {
  st *s = (st *)malloc(sizeof(st));
  int choice, element;
  while (1) {
    printf("Enter 1 to Create a stack\n");
    printf("Enter 2 to Push an element\n");
    printf("Enter 3 to Pop an element\n");
    printf("Enter 4 to Print the stack\n");
    printf("Enter 5 to Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      ces(s);
      break;
    case 2:
      printf("Enter the element to push: ");
      scanf("%d", &element);
      push(s, element);
      break;
    case 3:
      pop(s);
      break;
    case 4:
      printstack(s);
      break;
    case 5:
      free(s);
      printf("Exiting the program.\n");
      return 0;
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}