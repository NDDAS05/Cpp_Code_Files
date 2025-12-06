#include<stdio.h>
#include<stdlib.h>

//Basic Func
int* initArray(int size);
void getData(int *arr, int size);
void printData(int* arr, int size);
int* freeArray(int* arr);

//merge sort
void merge(int* arr, int l, int m, int r);

void mergeSort(int *arr, int l, int r)
{
        if(l<r)
        {
                int m= l + (r-l)/2;

                mergeSort(arr, l,m);
                mergeSort(arr, m+1,r);

                merge(arr, l,m, r);
        }
}

void merge(int* arr, int l, int m, int r)
{
        int size1=(m-l)+1;
        int size2=(r-m);

        int a1[size1], a2[size2];

        int i=0, j=0, arrIndex=l;

        for(;i<size1; i++, arrIndex++)
        {
                a1[i]=arr[arrIndex];
        }

        for(;j<size2;j++,arrIndex++)
        {
                a2[j]=arr[arrIndex];
        }


        i=j=0;
        arrIndex=l;

        while(i<size1 && j<size2)
        {
                if(a1[i] < a2[j])
                {
                        arr[arrIndex]=a1[i];
                        arrIndex++;
                        i++;
                }

                else{
                        arr[arrIndex]=a2[j];
                        arrIndex++;
                        j++;
                }
        }

        while(i<size1)
        {
                arr[arrIndex]=a1[i];
                arrIndex++;
                i++;
        }
        while(j<size2)
        {
                arr[arrIndex]=a2[j];
                arrIndex++;
                j++;
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

        printf("Sorting data using merge sort: ");
        mergeSort(arr, 0,size-1);
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
                                                                                                                                                                                                                                              

