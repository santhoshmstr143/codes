#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void insertion(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int c = a[i], j;
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > c)
            {
                a[j + 1] = a[j];
            }
        }
        a[j + 1] = c;
    }
}

void bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swap = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap = 1;
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (swap == 0)
        {
            break;
        }
    }
}

void selection(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void merge(int a[],int n, int start, int end)
{
    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge(a,n, start, mid);
    merge(a,n, mid + 1, end);

    int l = start, r = mid + 1, i = 0;
    int temp[end - start + 1];
    
    while (l <= mid || r <= end)
    {
        if (r > end || (l <= mid && a[l] < a[r]))
        {
            temp[i] = a[l];
            l++;
        }
        else
        {
            temp[i] = a[r];
            r++;
        }
        i++;
    }
    for (int j = 0; j < end - start + 1; j++)
    {
        a[j + start] = temp[j];
    }
}


int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int data[], int low, int high) {
    int pivot = data[low];  
    int too_big_index = low + 1;
    int too_small_index = high;

    while (too_small_index > too_big_index) {
        while (too_big_index <= high && data[too_big_index] <= pivot)
            ++too_big_index;

        while (too_small_index >= low && data[too_small_index] > pivot)
            --too_small_index;

        if (too_big_index < too_small_index)
            swap(&data[too_big_index], &data[too_small_index]);
    }

    swap(&data[too_small_index], &data[low]);  
    return too_small_index;  
}

void quicksort(int data[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(data, low, high);
        quicksort(data, low, pivot_index - 1);
        quicksort(data, pivot_index + 1, high);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // insertion(a,n);
    // bubble(a,n);
    // selection(a,n);    
    merge(a,n,0 , n-1);
    // quick(a,n-1);
    // qsort(a, n, sizeof(int), compare);
    // quicksort(a, 0, n - 1);
    printf("hi\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}