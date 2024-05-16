#include <stdio.h>

void bubbleSort(int array[], int size, int *count)
{
  int i, j, temp, swapped;

  for (i = 0; i < size - 1; i++)
  {
    swapped = 0; // Flag to check if any swaps occurred in the inner loop
    for (j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        // swap the elements
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        swapped = 1; // Set flag if a swap happened
        (*count)++;  // Increment step counter
      }
    }

    // If no swaps occurred in the inner loop, the array is already sorted
    if (!swapped)
    {
      break;
    }
  }
}

int main()
{
  int size, count = 0;
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter %d elements:\n", size);
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &array[i]);
  }

  printf("Original array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  bubbleSort(array, size, &count);

  printf("Sorted array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  printf("Total steps taken: %d\n", count);

  return 0;
}