#include <stdio.h>
#include <conio.h>
// #define MAX_SIZE 50;

void linear_search(int ar[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (ar[i] == num)
        {
            printf("Number found at %d\n", i);
            break;
        }
    }
    if (i == n)
        printf("Element not found \n");
}

void binary_search(int ar[], int n, int num)
{
    int beg = 0, end = n, mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (ar[mid] == num)
        {
            printf("Number found at %d\n", mid);
            break;
        }
        else if (ar[mid] < num)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        if (beg > end)
            printf("Element not found \n");
    }
}

void bubble_sort(int ar[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
    printf("Elements after Bubble Sortimg \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ->", ar[i]);
    }
}

void selection_sort(int ar[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[min])
            {
                min = j;
            }
        }
        int temp = ar[i];
        ar[i] = ar[min];
        ar[min] = temp;
    }
    printf("Elements after Selection Sortimg \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ->", ar[i]);
    }
}

void insertion_sort(int ar[], int n)
{
    int i, j, key;
    for (j = 1; j < n; j++)
    {
        key = ar[j];
        i = j - 1;
        while (i >= 0 && ar[i] > key)
        {
            ar[i + 1] = ar[i];
            i = i - 1;
        }
        ar[i + 1] = key;
    }
    printf("Elements after Insertion Sortimg \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ->", ar[i]);
    }
}

int main(void)
{
    int n, i, num;
    int ar[100];
    printf("Input length of th array    ");
    scanf("%d", &n);

    printf(" Enter the elements of the array of size : %d\n",
           n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    // printf("Input a number to search \n");
    // scanf("%d", &num);

    // linear_search(ar, n, num);
    // binary_search(ar, n, num);
    // bubble_sort(ar, n);
    // selection_sort(ar, n);
    insertion_sort(ar, n);
}