#include <stdio.h>
#include <conio.h>

int main()
{

    int ar[10];

    int n, mid, beg = 0, end = 9;
    printf("***** Binary Search Algorithm ************ \n");

    printf("enter array in sorted order  ");
    for (int x = 0; x < 10; x++)
    {
        printf("element %d : ", x + 1);
        scanf("%d", &ar[x]);
    }

    printf("Input a Number to Search");
    scanf("%d", &n);

    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (ar[mid] == n)
        {
            printf("Element found at : %d", mid);
            break;
        }

        else if (ar[mid] < n)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (beg > end)
        printf("Number not found");
}

/*  complexity  :  O(log n)**/