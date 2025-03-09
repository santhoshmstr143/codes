#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void mergeSort(int a[][2], int n, int start, int end)
{
    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(a, n, start, mid);
    mergeSort(a, n, mid + 1, end);

    int l = start, r = mid + 1, i = 0;
    int temp[end - start + 1][2];

    while (l <= mid || r <= end)
    {
        if (r > end || (l <= mid && (a[l][0] < a[r][0] || (a[l][0] == a[r][0] && a[l][1] < a[r][1]))))
        {
            temp[i][0] = a[l][0];
            temp[i][1] = a[l][1];
            l++;
        }
        else
        {
            temp[i][0] = a[r][0];
            temp[i][1] = a[r][1];
            r++;
        }
        i++;
    }

    for (int j = 0; j < end - start + 1; j++)
    {
        a[j + start][0] = temp[j][0];
        a[j + start][1] = temp[j][1];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n][2];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    mergeSort(a, n, 0, n - 1);
    int pre = a[0][1];
    for (int i = 1; i < n; i++)
    {
        if (a[i][1] >= pre)
        {
            pre = a[i][1];
        }
        else
        {
            pre = a[i][0];
        }
    }
    printf("%d\n", pre);
    return 0;
}