#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
	int x;
	x = *a;
	*a = *b;
	*b = x;
}

// Swap the value in int ** variable which is pointer to array
void swap_array(int **a, int **b) {
	int *x = *a;
	*a = *b;
	*b = x;
}

int main(int argc, char *argv[]) {
	int *arr = (int *)malloc(sizeof (int) * 5);
	int *brr = (int *)malloc(sizeof (int) * 5);
	int const_arr[] = {1, 2, 3, 4, 5};
	int const_brr[] = {6, 8, 9, 10, 11};

	if (argc != 3) {
		fprintf(stderr, "Usage: %s num1 num2\n", argv[0]);
		return;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("Before Swap: %d %d\n", a, b);
	swap(&a, &b);
	printf("After Swap: %d %d\n", a, b);
	
	printf("Array Before swap: %p %p\n", arr, brr);
	swap_array(&arr, &brr);
	printf("Array After swap: %p %p\n", arr, brr);

	return 0;
}


