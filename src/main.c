#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main(int argc,char *argv[])
{
	FILE *a;
	a=fopen(argv[1],"r");
	if(a==NULL)
	{
		printf("Cannot open file\n\n");
		return -1;
	}
	IntVector *v = int_vector_new(256);
	int elem;
	for(int i=0;getc(a)!=EOF;i++)
	{
		fseek(a,-1,SEEK_CUR);
		fscanf(a,"%d",&elem);
		int_vector_push_back(v, elem);
	}
	int_vector_shrink_to_fit(v);
	double tempTime = 0,realTime = 0;
	tempTime=wtime();
	bubble_sort(v);
	realTime=wtime()-tempTime;
	printf("bubble sort: %f\n\n",realTime);
	tempTime = 0;
	realTime = 0;
	tempTime=wtime();
	quick_sort(v,0,v->mas[v->used-1]);
	realTime=wtime()-tempTime;
	printf("quick sort: %f\n\n",realTime);
	int_vector_free(v);
	return 0;
}
