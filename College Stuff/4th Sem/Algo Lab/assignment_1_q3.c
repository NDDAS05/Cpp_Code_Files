#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int *init(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    if (!arr) {
        printf("Memory allocation failed for size %d\n", n);
        exit(1);
    }
    return arr;
}

void free_mem(int *arr) {
    free(arr);
}

void fill_random(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void copy_array(int *source, int *destn, int n) {
    memcpy(destn, source, sizeof(int) * n);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionSort(int *arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 3. Quick Sort
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int p_index = partition(arr, low, high);
        quickSort(arr, low, p_index - 1);
        quickSort(arr, p_index + 1, high);
    }
}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *arr1 = (int *)malloc(n1 * sizeof(int));
    int *arr2 = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) arr1[i] = arr[l + i];
    for (j = 0; j < n2; j++) arr2[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = arr1[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        j++; k++;
    }
    free(arr1);
    free(arr2);
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}



int main() {
    srand(time(NULL));

    int sizes[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};
    int num_sizes = 10;


    printf("Comparisons Below: \n");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < num_sizes; i++) {
        int current_size = sizes[i];
        
        int *original_arr = init(current_size);
        int *comp_arrr = init(current_size);
        
        fill_random(original_arr, current_size);

        clock_t start, end;
        double t_bubble, t_insert, t_quick, t_merge;

        // Bubble Sort
        copy_array(original_arr, comp_arrr, current_size);
        start = clock();
        bubbleSort(comp_arrr, current_size);
        end = clock();
        t_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Insertion Sort
        copy_array(original_arr, comp_arrr, current_size);
        start = clock();
        insertionSort(comp_arrr, current_size);
        end = clock();
        t_insert = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Quick Sort
        copy_array(original_arr, comp_arrr, current_size);
        start = clock();
        quickSort(comp_arrr, 0, current_size - 1);
        end = clock();
        t_quick = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Merge Sort
        copy_array(original_arr, comp_arrr, current_size);
        start = clock();
        mergeSort(comp_arrr, 0, current_size - 1);
        end = clock();
        t_merge = ((double)(end - start)) / CLOCKS_PER_SEC;



        printf(" Array %d\n Size: %d \n-----------------------\n\t 1. Bubble Sort: %f \n\t 2. Insertion Sort: %f \n\t 3. Quick Sort: %f \n\t 4. Merge Sort: %f. \n\n", i+1, current_size, t_bubble, t_insert, t_quick, t_merge);


        free_mem(original_arr);
        free_mem(comp_arrr);
    }

    return 0;
}