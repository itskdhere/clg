#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
// Structure to represent a queue
struct Queue
{
  int items[MAX_SIZE];
  int front;
  int rear;
};

// Function to initialize a queue
void initializeQueue(struct Queue *q)
{
  q->front = -1;
  q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q)
{
  return (q->rear == MAX_SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
  return (q->front == -1 && q->rear == -1);
}

// Function enqueue
void enqueue(struct Queue *q, int value)
{
  if (isFull(q))
  {
    printf("Queue is full. Cannot enqueue.\n");
    return;
  }
  if (isEmpty(q))
  {
    q->front = 0;
    q->rear = 0;
  }
  else
  {
    q->rear++;
  }
  q->items[q->rear] = value;
}

// Function dequeue
int dequeue(struct Queue *q)
{
  int removeditem;
  if (isEmpty(q))
  {
    printf("Queue is Empty. Cannot Dequeue");
    return -1;
  }
  removeditem = q->items[q->front];
  if (q->front == q->rear)
  {
    q->front = -1;
    q->rear = -1;
  }
  else
  {
    q->front++;
  }
  return removeditem;
}

// Function to get front element of the queue
int front(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is Empty");
    return -1;
  }
  return q->items[q->front];
}

// Function to get rear
int rear(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is Empty.");
    return -1;
  }
  return q->items[q->rear];
}

// Function to print
void printQueue(struct Queue *q)
{
  int i;
  if (isEmpty(q))
  {
    printf("Queue is empty.");
    return;
  }
  printf("Queue : ");
  for (i = q->front; i <= q->rear; i++)
  {
    printf(" %d", q->items[i]);
  }
  printf("\n");
}

// Main function
int main()
{
  struct Queue q;
  initializeQueue(&q);

  int choice, value;
  while (1)
  {
    printf("\n\nQueue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Front element\n");
    printf("4. Rear element\n");
    printf("5. Display queue\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to enqueue: ");
      scanf("%d", &value);
      enqueue(&q, value);
      break;
    case 2:
      dequeue(&q);
      break;
    case 3:
      printf("Front element: %d\n", front(&q));
      break;
    case 4:
      printf("Rear element: %d\n", rear(&q));
      break;
    case 5:
      printQueue(&q);
      break;
    case 6:
      printf("Exiting...\n");
      exit(0);
      break;
    default:
      printf("Invalid choice! Please enter a number between 1 to 6.\n");
    }
  }

  return 0;
}