#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"
IntVector *int_vector_new(size_t initial_capacity)
{
	IntVector *t = malloc(sizeof(IntVector));
	if (t==NULL)
		return NULL;
	t->mas=malloc(initial_capacity*sizeof(int));
	if (t->mas==NULL){
		free(t);
		return NULL;
	}
	t->used=0;
	t->capacity=initial_capacity;
	return t;
}

void int_vector_free(IntVector *v)
{
	free(v->mas);
	free(v);
	v->capacity=0;
	v->used=0;
}

int int_vector_push_back(IntVector *v, int item)
{
	if ((v->used)<(v->capacity)){
		v->mas[v->used] = item;
		v->used++;
	}
	else {
		v->capacity*= 2;
		if(v->capacity==0) v->capacity++;
		int *t = realloc(v->mas, v->capacity*sizeof(int));
			if (t == NULL)
				return -1;
		v->mas = t;
		v->mas[v->used] = item;
		v->used++;
	}
	return 0;
}

int int_vector_shrink_to_fit(IntVector *v)
{
	if ((v->used)<(v->capacity)) 
	{
		v->capacity=v->used;
		return 0;
	}
	return -1;
}
