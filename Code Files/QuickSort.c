#include<stdio.h>
#include<stdlib.h>

int* initArray(int size);
void getData(int *arr, int size);
void printData(int* arr, int size);
int* freeArray(int* arr);


void swap(int* a, int* b)
{
        *a=*a + *b;
        *b=*a - *b;
        *a=*a - *b;
}

int median(int a, int b, int c)
{
       if((a>b)!=(a>c))
       {
              return a;
       }

       else if((b>a)!=(b>c))
       {
              return b;
       }
       else
              return c;
}

int pivot(int* arr, int low, int high)
{
        int size=(high-low)+1;
        int mid=low+(low+high)/2;

        int val=median(arr[low], arr[mid], arr[high]);
        if(val==arr[mid])
                swap(&arr[low],&arr[mid]);
        else if(val==arr[high])
                swap(&arr[low],&arr[high]);

        int piv=low;
        int i=low;
        int j=high;

        while(i<j)
        {
                while(arr[i]<=arr[piv] && i<size)
                {
                       i++;
                }

                while(arr[j]>=arr[piv] && j>0)
                {
                       j--;
                }

                if(i<j)
                {
                       swap(&arr[i], &arr[j]);
                }
        }

        swap(&arr[piv], &arr[j]);
        return j;
}
void quickSort(int *arr, int l, int r)
{
        if(l<r)
        {
               int piv=pivot(arr, l, r);
               quickSort(arr, l, piv-1);
               quickSort(arr, piv+1, r);
        }
}


int main()
{
        int *arr=NULL;
        int size=0;

        printf("Enter array size: ");
        scanf("%d",&size);
        printf("Enter data: \n");

        arr=initArray(size);
        if(arr==NULL)
        {
               printf("Allocation failed.");
              exit(1);
        }

        printf("Sorting data using quick sort: ");
        quickSort(arr, 0,size-1);
        printf("\n");
        printData(arr, size);
        return 0;
}

int* initArray(int size)
{
        int* temp=(int*)malloc(sizeof(int) * size);

        if(temp==NULL)
        {
                printf("Memory allocation failed. Exiting.\n");
                exit(1);
        }

        getData(temp,size);
        return temp;
}

void getData(int *arr, int size)
{
        for(int i=0;i<size;i++)
        {
                scanf("%d",&arr[i]);
        }
}

void printData(int* arr, int size)
{
        if(arr==NULL)
        {
                printf("NULL\n");
                return;
        }
        printf("Printing list: ");
        for(int i=0; i<size;i++)
        {
                printf(" %d",arr[i]);
        }
        printf("\n");
}

int* freeArray(int* arr)
{
        if(arr==NULL)
        {
                return NULL;
        }

        free(arr);
        arr=NULL;
        return arr;
}

