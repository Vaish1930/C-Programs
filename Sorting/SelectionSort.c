#include <stdio.h>
#include <conio.h>

int main()
{
    int ar[10];

    printf("enter array elements");
    for (int x = 0; x < 10; x++)
    {
        printf("element %d : ", x + 1);
        scanf("%d", &ar[x]);
    }

    for (int x = 0; x <= 10 - 1; x++)
    {
        int min_index = x;

        for (int j = x + 1; j < 10; j++)
        {

            if (ar[j] < ar[min_index])
            {
                min_index = j;
            }
        }
        int temp = ar[min_index];
        ar[min_index] = ar[x];
        ar[x] = temp;
    }

    printf("sorted array \n");
    for (int x = 0; x < 10; x++)
    {
        printf("%d ! ", ar[x]);
    }
    return 0;
}

/*Time Complexity: O(n2) as there are two nested loops.
Auxiliary Space: O(1)
The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
Time Complexities:
Worst Case Complexity: O(n2)
If we want to sort in ascending order and the array is in descending order then, the worst case occurs.
Best Case Complexity: O(n2)
It occurs when the array is already sorted
Average Case Complexity: O(n2)
It occurs when the elements of the array are in jumbled order (neither ascending nor descending). 
 **/