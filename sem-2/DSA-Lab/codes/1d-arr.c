#include <stdio.h>

int main()
{
    int n, a, s, found=0;

    printf("Enter Number Of Elements: ");
    scanf("%d", &n);
    int arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter Element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nEnter Number To Add In Each Element: ");
    scanf("%d", &a);

    printf("\nNew Array: ");
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = arr[i] + a;
        printf("%d  ", arr[i]);
    }

    printf("\n\nEnter The Number To Search: ");
    scanf("%d", &s);

    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == s)
        {
            printf("\nElement Found At %d", i+1);
            found=1;
            break;
        }
    }

    if(!found)
        printf("\nElement Not Found");

    printf("\n\nSorted Array: ");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[i] > arr[j])
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}