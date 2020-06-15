#include <stdlib.h>
#include <stdio.h>
#include "IntVector.h"
#include <sys/time.h>
double wtime()
{
	struct timeval t;
	gettimeofday(&t,NULL);
	return (double)t.tv_sec + (double)t.tv_usec*1E-6;
}

int bubble_sort(IntVector *v)
{
	int i,j;
	for(i=v->used-1;i>0;i--)
	{
		for(j=i;j<i;j++)
		{
			if(v->mas[j]>v->mas[j+1])
			{
				int buf;
				buf=v->mas[j];
				v->mas[j]=v->mas[j+1];
				v->mas[j+1]=buf;
			}
		}
	}	
	return 0;
}

int quick_sort(IntVector *q,int begin,int end)
{
    int buf,i=begin, j=end, x=q->mas[(begin+end)/2];
    do {
        while (q->mas[i] < x) i++;
        while (q->mas[j] > x) j--;
        if(i<=j) {
            if (q->mas[i]>q->mas[j])
            {
			buf=q->mas[i];
			q->mas[i]=q->mas[j];
			q->mas[j]=buf;
			}
            i++;
            j--;
        }
    } while (i <= j);
  
    if (i < end)
        quick_sort(q, i, end);
    if (begin< j)
        quick_sort(q, begin, j);
    return 0;
}
