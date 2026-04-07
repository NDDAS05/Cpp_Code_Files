#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	FILE* fwrite;
	int rnd_int,n,max=-1,min=110;
	
	printf("Enter the number of random integers to generate: ");
	scanf("%d",&n);

	fwrite=fopen("assignment1_Q1_random_num.txt", "w");
	if(fwrite==NULL) { 
		printf("Error occured."); 
		return 1;
	}
	
	srand(time(NULL));
	
	while(n--)
	{
		rnd_int=rand()%100 + 1;
		fprintf(fwrite,"%d\n",rnd_int);
	}

	fclose(fwrite);

	FILE* fread;

	printf("Reading file....\n");
	fread=fopen("assignment1_Q1_random_num.txt", "r");
	
	if(!fread){
		printf("Error occured.\n"); 
		return 1;
	}


	while(fscanf(fread, "%d", &rnd_int)!=EOF)
	{
		printf("%d ",rnd_int);
		if(rnd_int>max) max=rnd_int;
		if(rnd_int<min)	min=rnd_int;
	}

	printf("\nMaximum: %d\nMinimum: %d\n",max,min);
	return 0;
}
