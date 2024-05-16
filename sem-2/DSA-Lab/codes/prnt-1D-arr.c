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
  printf("Array = \n");
  for (int i = 0; i < row; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}