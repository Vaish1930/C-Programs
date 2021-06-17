#include <stdio.h>
#include <conio.h>

int main()
{
    int ar[10];
    printf("***** bubble sort Algorithm ************ \n");

    printf("enter array  ");
    for (int x = 0; x < 10; x++)
    {
        printf("element %d : ", x + 1);
        scanf("%d", &ar[x]);
    }
    //sorting part

    for (int x = 0; x <= 10; x++)
    {
        for (int y = 0; y <= 9; y++)
        {
            if (ar[y] < ar[y + 1])
            {
                int temp = ar[y];
                ar[y] = ar[y + 1];
                ar[y + 1] = temp;
            }
        }
    }

    printf("sorted array \n");
    for (int x = 0; x <= 10; x++)
    {
        printf("%d -> ", ar[x]);
    }
    return 0;
}

/*
 time complexity of Bubble Sort is O(n2).
 The space complexity for Bubble Sort is O(1), because only a single additional memory space is required i.e. for temp variable.
Also, the best case time complexity will be O(n), it is when the list is already sorted.
Worst Case Time Complexity [ Big-O ]: O(n2)
Best Case Time Complexity [Big-omega]: O(n)
Average Time Complexity [Big-theta]: O(n2)
Space Complexity: O(1)
 **/