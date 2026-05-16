#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 50000

int *init()
{
    int *arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
    {
        printf("Error occured in allocating memory.\n");
        exit(1);
    }
    return arr;
}

int lin_search(int *arr, int elem, int *comp)
{
    *comp = 0;
    if (!arr)
    {
        printf("Array not found.\n");
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        (*comp)++;
        if (arr[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

void merge(int *arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int arr1[n1], arr2[n2];
    int i, j, k;

    for (i = 0; i < n1; i++)
        arr1[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int bin_search(int *arr, int *comp, int elem)
{
    *comp = 0;
    int start = 0, end = size - 1;

    while (start <= end)
    {
        (*comp)++;
        int mid = start + (end - start) / 2;

        if (arr[mid] == elem)
            return mid;
        else if (elem < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int main()
{
    int *arr = init();
    int elem;
    clock_t start, end;
    double time_lin, time_bin;

    srand(time(NULL));
    printf("Filling the array....\n");
    for (int i = 0; i < size; i++)
    {
        int rand_num = (rand() % 50000) + 1;
        arr[i] = rand_num;
    }

    mergeSort(arr, 0, size - 1);

    int comp_lin = 0, comp_bin = 0;

    printf("Enter the number to search: ");
    scanf("%d", &elem);

    start = clock();
    lin_search(arr, elem, &comp_lin);
    end = clock();
    time_lin = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    int idx_bin = bin_search(arr, &comp_bin, elem);
    end = clock();
    time_bin = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (idx_bin != -1)
        printf("Element found at index: %d\n", idx_bin);
    else
        printf("Element not found.\n");

    printf("Linear Search Comparisons: %d\n", comp_lin);
    printf("Linear Search Time: %f seconds\n", time_lin);

    printf("Binary Search Comparisons: %d\n", comp_bin);
    printf("Binary Search Time: %f seconds\n", time_bin);

    free(arr);
    return 0;
}