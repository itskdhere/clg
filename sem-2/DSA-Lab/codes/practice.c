#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int capacity;
  int top;
  int *arr;
};

typedef struct Stack st;

st *createStack(int cap)
{
  st *stack = (st *)malloc(sizeof(st));
  stack->arr = (int *)malloc(cap * sizeof(int));
  stack->capacity = cap;
  stack->top = -1;
}

int isStackOverflow(st *stack)
{
  return (stack->top == stack->capacity - 1);
}

int isStackUnderflow(st *stack)
{
  return (stack->top == -1);
}

void push(st *stack)
{
  if (isStackOverflow(stack))
  {
    printf("Stack Overflow");
    return;
  }
  int val;
  printf("Enter value to push: ");
  scanf("%d", &val);
  stack->top += 1;
  stack->arr[stack->top] = val;
  printf("Pushed element: %d", stack->arr[stack->top]);
}

void pop(st *stack)
{
  if (isStackUnderflow(stack))
  {
    printf("Stack Underflow");
    return;
  }
  printf("Popped element: %d", stack->arr[stack->top]);
  stack->top -= 1;
}

void peek(st *stack)
{
  if (isStackUnderflow(stack))
  {
    printf("Stack Underflow");
    return;
  }
  printf("Top element: %d", stack->arr[stack->top]);
}

void display(st *stack)
{
  printf("Current stack:\n");
  for (int i = 0; i <= stack->top; i++)
  {
    printf("%d\t", stack->arr[i]);
  }
}

int main()
{
  int cap, op, val;
  printf("Enter the capacity of the stack: ");
  scanf("%d", &cap);
  st *stack = createStack(cap);
  while (1)
  {
    printf("\n\n0: Exit \n1: Push \n2: Pop \n3: Peek \n4: Display");
    printf("\nSelect option: ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
      free(stack);
      exit(0);
      break;
    case 1:
      push(stack);
      break;
    case 2:
      pop(stack);
      break;
    case 3:
      peek(stack);
      break;
    case 4:
      display(stack);
      break;
    default:
      printf("Invalid Option...");
      break;
    }
  }
  free(stack);
  return 0;
}