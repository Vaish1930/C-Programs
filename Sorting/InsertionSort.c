#include <stdio.h>
#include <conio.h>

int main()
{
    int ar[10], key, i;

    printf("***** Insertion Sort Algorithm ********* \n");

    printf("enter array elements  ");
    for (int x = 0; x < 10; x++)
    {
        printf("element %d : ", x + 1);
        scanf("%d", &ar[x]);
    }

    for (int j = 1; j < 10; j++)
    {
        key = ar[j];

        i = j - 1;

        while (i > -1 && ar[i] > key)
        {
            ar[i + 1] = ar[i];

            i = i - 1;
        }

        ar[i + 1] = key;
    }

    printf("sorted array \n");
    for (int x = 0; x < 10; x++)
    {
        printf("%d -> ", ar[x]);
    }
    return 0;
}

// Best Case Complexity : O(n)
// Worst Case Complexity : 0(n2)
// In place , Stable