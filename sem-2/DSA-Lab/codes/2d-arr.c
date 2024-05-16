#include <stdio.h>

int main()
{
    int m = 3;
    int n = 3;
    int arr[m][n];
    int found = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter Value For %d - %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nCurrent 2D Array:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int x = i; x < m; x++)
            {
                for (int y = j; y < n; y++)
                {
                    if (arr[i][j] < arr[x][y])
                    {
                        int temp = arr[i][j];
                        arr[i][j] = arr[x][y];
                        arr[x][y] = temp;
                    }
                }
            }
        }
    }

    printf("\nSorted 2D Array:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}