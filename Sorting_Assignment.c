//Assignment 8
//Q 1.a) Insertion sort - i) Defailt Algorithm ii) Without Swap
//Assuming Ascending Order

#include<stdio.h>
#include<stdlib.h>
int* initArray(int size);
void getData(int *arr, int size);
void printData(int* arr, int size);
int* freeArray(int* arr);


//i) Default Algorithm
void swap(int* a, int* b)
{
	*a= *a + *b;
	*b= *a - *b;
	*a= *a - *b;
}

void insertionSort_with_swap(int *arr, int size)
{
	int i=0,j=0;
	for(i=1;i<size;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
			else
				break;
		}
	}

	printData(arr, size);
}


//ii) No Swaps
void insertionSort_no_swap(int *arr, int size)
{
	int j,prev=0,curr=0;

	for(j=1;j<size;j++)
	{
		prev=j-1;
		curr=arr[j];
		while(prev>=0 && arr[prev]>curr)
		{
			arr[prev+1]=arr[prev];
			prev--;
		}
		arr[prev+1]=curr;
	}

	printData(arr, size);
}


int main()
{
	int op,size=0;
	int *arr=NULL;
	printf("\nAssignment 8; Question 1.a (Insertion Sort)\n---------------------------------------\n");

	while(1)
	{
		printf("Choose option:\n\t1. Create list\n\t2. Insertion sort with swap\n\t3. Insertion sort without swap\n\t4. Free array\n\t5. Print List\n\t6. Exit\n");

		printf("Enter choice: ");
		scanf("%d",&op);

		switch(op)
		{
			case 1: printf("Enter size: ");
					scanf("%d",&size);
					printf("Enter data: \n");
					arr=initArray(size);
					break;

			case 2: if(arr==NULL)
					{
						printf("List empty.\n");
						break;
					}
					insertionSort_with_swap(arr, size);
					break;

			case 3: if(arr==NULL)
					{
						printf("List empty.\n");
						break;
					}
					insertionSort_no_swap(arr, size);
					break;

			case 4: arr=freeArray(arr);
					printf("Array freed.\n");
					break;

			case 5: printData(arr,size);
					break;

			case 6: arr=freeArray(arr);
					printf("Exiting... \n\n");
					exit(1);
					
			default: printf("Choose correct option.\n");
		}	
	}
	
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
