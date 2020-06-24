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
	int i,j,buf;
	for(i=0;i<v->used-1;i++)
	{
		for(j=v->used-1;j>i;j--)
		{
			if(v->mas[j-1]>v->mas[j])
			{
				buf=v->mas[j-1];
				v->mas[j-1]=v->mas[j];
				v->mas[j]=buf;
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
    if (j<end)
        quick_sort(q,i,end);
    if (j>begin)
        quick_sort(q,begin,j);
    return 0;
}
