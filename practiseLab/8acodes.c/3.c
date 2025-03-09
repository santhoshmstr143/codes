#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int find(int a[], int x, int l, int r)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (a[mid] == x)
        return mid;
    if (a[mid] > x)
        return find(a, x, l, mid - 1);
    else
        return find(a, x, mid + 1, r);
}

int main()
{
    int q;
    scanf("%d", &q);
    int n = 0;
    int a[10000], x, op, k;

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            int c = x, j;
            for (j = n - 1; j >= 0; j++)
            {
                if (a[j] > c)
                {
                    a[j + 1] = a[j];
                }
            }
            a[j + 1] = c;
            n++;
        }
        else if (op == 2)
        {
            scanf("%d %d", &x, &k);
            int ind = find(a, x, 0, n - 1);
            if (ind != -1)
            {
                if (ind + k < n)
                {
                    printf("%d\n", a[ind + k]);
                }
                else
                {
                    printf("-1\n");
                }
            }
            else
            {
                printf("-1\n");
            }
        }
    }

    return 0;
}