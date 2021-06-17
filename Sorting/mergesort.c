#include <stdio.h>
#include <conio.h>

void merge(int a[], int mid, int low, int high)
{
    int i, j, k, b[100];

    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int x = 0; x <= high; x++)
    {
        a[x] = b[x];
    }
}

void mergeSort(int ar[], int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(ar, low, mid);
        mergeSort(ar, mid + 1, high);
        merge(ar, mid, low, high);
    }
}

void display(int ar[], int h)
{
    printf("sorted array \n");
    for (int x = 0; x <= h; x++)
    {
        printf("%d -> ", ar[x]);
    }
}

int main()
{

    int ar[] = {434, 5, 6, 33, 2, 23, 1};
    int l = 0;
    int h = 6;

    mergeSort(ar, l, h);
    display(ar, h);
}