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
	IntVector *s = int_vector_new(256);
	int elem,i;
	for(i=0;getc(a)!=EOF;i++)
	{
		fseek(a,-1,SEEK_CUR);
		fscanf(a,"%d",&elem);
		int_vector_push_back(v, elem);
		int_vector_push_back(s, elem);
	}
	int_vector_shrink_to_fit(v);
	int_vector_shrink_to_fit(s);
	FILE *b,*c;
	b=fopen("output1.txt","w+");
	c=fopen("output2.txt","w+");
	double tempTime = 0,realTime = 0;
	tempTime=wtime();
	bubble_sort(v);
	realTime=wtime()-tempTime;
	printf("bubble sort: %f\n\n",realTime);
	for(i=1;i<v->used;i++)
	{
		fprintf(b,"%d",v->mas[i]);
		fputs("\n",b);
	}
	int_vector_free(v);
	tempTime = 0;
	realTime = 0;
	tempTime=wtime();
	quick_sort(s,0,s->mas[s->used-1]);
	realTime=wtime()-tempTime;
	printf("quick sort: %f\n\n",realTime);
	for(i=1;i<s->used;i++)
	{
		fprintf(c,"%d",s->mas[i]);
		fputs("\n",c);
	}
	int_vector_free(s);
	fclose(a);
	fclose(b);
	fclose(c);
	return 0;
}
