#include <stdio.h>
int main()
{
    int n, t, flag1, flag2, j, total = 0, i;
    int m;
    scanf("%i %i", &n, &m);
    int a[n], b[m];
    for (i = 0; i < n; i++)
        scanf("%i", &a[i]);

    for (i = 0; i < m; i++)
        scanf("%i", &b[i]);

    int lcm = a[n - 1];
    int max = b[0];
    int size = n + m;
    int c[size], k = 0;
    for (int i = lcm; i <= max; i++)
    {
        if (max % i == 0)
        {
            c[k] = i;
            k++;
        }
    }

    int count = 0, flag = 0;
    for (int i = 0; i < 4; i++)
    {
        int n = c[i];
        for (int j = 0; j < m; j++)
        {

            if (b[j] % n != 0)
            {
                break;
            }
            else
                flag = 1;
            if (flag == 1)
                count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
