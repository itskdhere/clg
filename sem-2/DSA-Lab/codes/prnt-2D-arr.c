#include <stdio.h>
int main()
{
  int row, column;
  int i, j;
  printf("Write array size: ");
  scanf("%d%d", &row, &column);
  int arr[row][column];

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < column; j++)
    {
      printf("[%d][%d]= ", i, j);
      scanf("%d", &arr[i][j]);
    }
    printf("\n");
  }
  printf("Array = \n");
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < column; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}