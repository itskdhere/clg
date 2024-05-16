// 17-01-2024 = Data Structure-LAB
#include <stdio.h>
int main()
{
  int row;
  printf("Write array size: ");
  scanf("%d", &row);
  int arr[row];

  for (int i = 0; i < row; i++)
  {
    printf("%d = ", i);
    scanf("%d", &arr[i]);
  }
  
  printf("Sorted array = \n");
  for (int i = 0; i < row; i++)
  {
    for (int j = i; j < row; j++)
    {
      if (arr[i] > arr[j])
      {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    printf(" %d ", arr[i]);
  }

  return 0;
}