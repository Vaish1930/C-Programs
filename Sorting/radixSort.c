#include <math.h>
#include <stdio.h>

int max_number(int a[], int n) {
  int i, max = 0;
  for (i = 0; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

void count_sort(int a[], int exp, int n) {
  int i, count[10] = {0}, output[n];
  for (i = 0; i < n; i++) {
    count[(a[i] / exp) % 10]++;
  }
  for (i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  for (i = n - 1; i >= 0; i--) {
    output[count[(a[i] / exp) % 10] - 1] = a[i];
    count[(a[i] / exp) % 10]--;
  }
  for (i = 0; i < n; i++) {
    a[i] = output[i];
  }
}

void radix_sort(int a[], int n) {
  int max = max_number(a, n), exp;
  for (exp = 1; max / exp > 0; exp *= 10) {
    count_sort(a, exp, n);
  }
  //
}

void main() {
  int n, max, d;
  printf("Radix sort implementation..............\nEnter the array size = ");
  scanf("%d", &n);
  int a[n], i;
  printf("\nEnter the array elements.......\n");
  for (i = 0; i < n; i++) {
    printf("Enter an element at %d = ", i + 1);
    scanf("%d", &a[i]);
  }
  max = max_number(a, n);
  //	d=digit_count(max);
  radix_sort(a, n);
  printf("\nArray after radix sort is : [");
  for (i = 0; i < n; i++) {
    printf("%d,", a[i]);
  }
  printf("]");
}