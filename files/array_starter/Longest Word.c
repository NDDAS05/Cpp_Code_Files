//Longest Word
#include<stdio.h>

void largest_word(char str[])
{
	int i,k=1,max_index,min_index,space_count_index[100],j;
	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
		{
			space_count_index[k]=i;
			k++;
		}
	}
	
	space_count_index[k]=i; // Last index storing the position of \n
	space_count_index[0]=(-1); //Assuming space before 1st char is entered is -1
	max_index=space_count_index[0];
	min_index=space_count_index[0];
	for(j=1;j<=k;j++)
	{
		if((space_count_index[j]-space_count_index[j-1]-1)>=max_index) //Additional (-1) is there to exclude the space in the end of string
		{
			max_index=space_count_index[j];
			min_index=space_count_index[j-1];
		}
	}
	
	printf("Longest word: \n");
	for(i=min_index+1;i<=max_index-1;i++)
	{
		printf("%c",str[i]);
	}
}

int main(){
	
	char string[100];
	
	printf("Enter your string: ");
	scanf("%[^\n]",string);
	
	largest_word(string);
	
	return 0;
}