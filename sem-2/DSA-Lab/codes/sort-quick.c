#include <stdio.h>

// function to swap elements
void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
// function to find the partition position
int partition(int array[], int low, int high)
{

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// main function
int main()
{
  int i, r;
  printf("Write the size of array : ");
  scanf("%d", &r);
  int arr[r];
  for (i = 0; i < r; i++)
  {
    printf("element at %d = ", i);
    scanf("%d", &arr[i]);
  }

  printf("Unsorted Array : \n");
  printArray(arr, r);

  // perform quicksort on data
  quickSort(arr, 0, r - 1);

  printf("Sorted array in ascending order : \n");
  printArray(arr, r);

  return 0;
}