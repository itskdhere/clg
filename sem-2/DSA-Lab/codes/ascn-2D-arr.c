#include <stdio.h>
int main()
{
  int row, column;
  int i, j, k, l, temp;
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
  
  printf("After sorting array = \n");
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < column; j++)
    {
      for (k = 0; k < row; k++)
      {
        for (l = 0; l < column; l++)
        {
          if (arr[i][j] < arr[k][l])
          {
            temp = arr[i][j];
            arr[i][j] = arr[k][l];
            arr[k][l] = temp;
          }
        }
      }
    }
  }

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < column; j++)
    {
      printf(" %d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}