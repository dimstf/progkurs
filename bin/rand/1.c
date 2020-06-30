#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *a;
    a=fopen("rand15.txt","w+");
    srand(time(NULL));
    int i,n=32768,k;
    for(i=0;i<n;i++)
    {
	k=rand()%1000;
	fprintf(a,"%d",k);
	fputs("\n",a);
    }
    return 0;
}