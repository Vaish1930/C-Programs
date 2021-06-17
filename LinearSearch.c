#include <stdio.h>
#include <conio.h>

int main()
{

    int ar[10];

    int n, i;
    printf("***** Linear Search Algorithm ************ \n");

    printf("enter array  ");
    for (int x = 0; x < 10; x++)
    {
        printf("element %d : ", x + 1);
        scanf("%d", &ar[x]);
    }

    printf("Input a Number to Search");
    scanf("%d", &n);

    for (i = 0; i < 10; i++)
    {
        if (n == ar[i])
        {

            printf(" Number  was found on Index : %d", i);
            break;
        }
    }
    if (i == 10)
    {

        printf("Element not found");
    }
}

/* 
The complexity of Linear Search Technique
Time Complexity: O(n)
Space Complexity: O(1)  
**/