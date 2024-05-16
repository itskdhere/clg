#include <stdio.h>

void bubbleSort(int array[], int size)
{
  int i, j, temp, count = 0;
  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      count++; // Increment step count for each comparison
      if (array[j] > array[j + 1])
      {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  printf("Step count: %d\n", count);
}

int main()
{
  int size, count = 0;
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  int array[size];

  printf("\nEnter %d elements:\n", size);
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &array[i]);
  }

  printf("\nOriginal array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n\n");

  bubbleSort(array, size);

  printf("\nSorted array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n\n");

  return 0;
}