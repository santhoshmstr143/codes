#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int arr1 = mid - left + 1;
    int arr2 = right - mid;
    int L[arr1], R[arr2];
    for (int i = 0; i < arr1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < arr2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < arr1 && j < arr2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < arr1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < arr2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    int l = 0, r = n - 1, count = 0;
    while (l <= r)
    {
        int sum = a[l] + a[r];
        if (sum <= x)
        {
            count++;
            l++;
            r--;
        }
        else
        {
            count++;
            r--;
        }
    }
    printf("%d\n", count);
}