#include <stdio.h>
#include <stdlib.h>

int* init(int n) {
        int *arr = (int*) malloc(n * sizeof(int));
        if (arr==NULL) {
                printf("Memory allocation failed.\n"); exit(1);
        }
        return arr;
}

void printArray(int *a, int n)
{
        for (int i = 0; i < n; i++)
                printf("%d ", a[i]);
        printf("\n");
}

void bubble_default(int *a, int n,int *swapCount)
{
        *swapCount=0;
        for (int i = 0; i < n - 1; i++)
        {
                for (int j = 0; j < n - i - 1; j++)
                {
                        if (a[j] > a[j + 1])
                        {
                                int t = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = t;
                                (*swapCount)++;
                         }
                }
        }
}

void bubble_no_swap(int *a, int n,int *swapCount)
{       *swapCount=0;
        for (int i = 0; i < n - 1; i++)
        {
                for (int j = 0; j < n - i - 1; j++)
                {
                        if (a[j] > a[j + 1])
                        {
                                a[j] = a[j] + a[j + 1];
                                a[j + 1] = a[j] - a[j + 1];
                                a[j] = a[j] - a[j + 1];
                        }
                }
        }

}

void bubble_flagged(int *a, int n, int *swapCount)
{       *swapCount=0;
        for (int i = 0; i < n - 1; i++)
        {
                int swapped = 0;
                for (int j = 0; j < n - i - 1; j++)
                {
                        if (a[j] > a[j + 1])
                        {
                                int t = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = t;
                                (*swapCount)++;
                                swapped = 1;
                        }
                 }
                 if (!swapped) break;

        }
}

void bubble_range_limit(int *a, int n, int *swapCount)
{
        *swapCount=0;
        int lim = n - 1;
        while (lim > 0) {
                int lastSwap = 0;
                for (int j = 0; j < lim; j++)
                {
                        if (a[j] > a[j + 1]) {
                                int t = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = t;
                                lastSwap = j;
                                (*swapCount)++;
                        }
                }
                lim = lastSwap;
        }

}

void bubble_alternating(int *a, int n, int *swapCount)
{
        *swapCount=0;
        int start = 0, end = n - 1;
        int swapped = 1;
        while (swapped) {
                swapped = 0;
                for (int i = start; i < end; i++){
                        if (a[i] > a[i + 1]) {
                                int t = a[i];
                                a[i] = a[i + 1];
                                a[i + 1] = t;
                                swapped = 1;
                                (*swapCount)++;
                        }
                }
                if (!swapped)
                        break;
                end--;
                swapped = 0;
                for (int i = end; i > start; i--)
                {
                        if (a[i] < a[i - 1])
                        {
                                int t = a[i];
                                a[i] = a[i - 1];
                                a[i - 1] = t;
                                swapped = 1;
                                (*swapCount)++;
                        }
                }
                start++;
        }

}

int main() {
        int *arr = NULL;
        int n = 0, choice;
        int swapCount=0;

        while (1) {
        printf("\nChoose an option:\n");
        printf("1. Create new array\n");
        printf("2. Print array\n");
        printf("3. Sort (choose method)\n");
        printf("4. Free array\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

    if (choice == 1) {
        if (arr)
                free(arr);
        printf("Enter array size: ");
        scanf("%d", &n);
        arr = init(n);
        printf("Enter %d elements: ",n);
        for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);
    }
    else if (choice == 2) {
        if (!arr)
                printf("Array not created yet.\n");
        else
                printArray(arr, n);
    }
    else if (choice == 3) {
        if (!arr) {
            printf("Create an array first.\n");
            continue;
        }
        printf("Select sorting method:\n");
        printf("1. Default Bubble Sort\n");
        printf("2. Bubble Sort (No Swap Variable)\n");
        printf("3. Flagged Bubble Sort\n");
        printf("4. Range Limiting Bubble Sort\n");
        printf("5. Alternating Bubble Sort\n");
        printf("Enter: ");
        printf("Enter: ");
        int m;
        scanf("%d", &m);

        switch (m) {
            case 1: bubble_default(arr, n, &swapCount);

                        printf("\nArray is: \n");
                        printArray(arr,n);
                        printf("\nSwaps: %d\n",swapCount);
                    break;

            case 2: bubble_no_swap(arr, n, &swapCount);

                        printf("\nArray is: \n");
                        printArray(arr,n);
                        printf("\nSwaps: %d\n",swapCount);
                    break;

            case 3: bubble_flagged(arr, n, &swapCount);

                        printf("\nArray is: \n");
                        printArray(arr,n);
                        printf("\nSwaps: %d\n",swapCount);
                    break;

            case 4: bubble_range_limit(arr, n, &swapCount);
                        printf("\nArray is: \n");
                        printArray(arr,n);
                        printf("\nSwaps: %d\n",swapCount);
                    break;

            case 5: bubble_alternating(arr, n, &swapCount);
                        printf("\nArray is: \n");
                        printArray(arr,n);
                        printf("\nSwaps: %d\n",swapCount);
                    break;

            default: printf("Invalid choice.\n"); continue;
        }
    }
    else if (choice == 4) {
        if (arr) {
            free(arr);
            arr = NULL;
            printf("Array freed.\n");
        } else printf("No array to free.\n");
    }
    else if (choice == 5) {
        if (arr) free(arr);
        return 0;
    }
    else printf("Invalid choice.\n");
 }

}
