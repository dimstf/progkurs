#if !defined iv_h
#define iv_h
typedef struct{
	int *mas;
	int used;
	int capacity;
} IntVector;

double wtime();
IntVector *int_vector_new(size_t initial_capacity);
void int_vector_free(IntVector *v);
int int_vector_push_back(IntVector *v, int item);
int int_vector_shrink_to_fit(IntVector *v);
int bubble_sort(IntVector *v);
int quick_sort(IntVector *q,int begin,int end);

#endif
