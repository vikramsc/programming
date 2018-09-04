#include <stdio.h>
#include <malloc.h>


// https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/

/*
 * int a[10];					// Allocated in stack frame
 * int *a = (int *)malloc(sizeof(int) * 10);	// Allocated from heap
 */
void arrays_are_pointers() {
	int *p = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};  	// Not Valid, compiled with warning, but referring this will fail
	int b[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};	// Both are allowed
	int a[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	int i = 0;

	//for (i = 0; i < 10; i++) {
	//	printf("%d\n", *(p + i));			// Lead to seg fault
	//}

	for (i = 0; i < 10; i++) {
		printf("%p %p\n", &a[i], (a + i));		// Both are same
		printf("%p %p\n", &a[0], a);			// Both are same
		printf("%d %d\n", a[i], *(a + i));		// Both are same
		printf("%d %d\n", a[0], *a);			// Both are same
	}
}

/*
 * a[2][2]: memory allocation a[0][0], a[0][1], a[1][0], a[1][1]
 * *d[2]: memory allocation ???
 */
void twod_arrays() {
	//int a[][] = { {1, 2}, {3, 4}, {5, 6}};		// Not allowed compilation error as compilation requires size of inner array
	int a[][2] = { {1, 2}, {3, 4}, {5, 6}};			// valid
	// int a[2][] = { {1, 2}, {3, 4}, {5, 6}};		// Invalid	
	int b[3][2] = { {1, 2}, {3, 4}, {5, 6}};		// valid
	//int *c[2] = { {1, 2}, {3, 4}, {5, 6}};		// Not valid, compiled with warning, but reffering this will fail
	int *d[2] = {1, 2, 3, 4, 5, 6};				// valid ???
	int i, j;
	int **e, **f;

	//for (i = 0; i < 3; i++) {
	//	printf("%d\n", c[i][1]);			// Lead to Seg fault
	//}

	for (i = 0; i < 6; i++) {
		//printf("%d %d\n", (d + i)[0], (d + i)[1]);
		//printf("%p %p\n", &((d +i)[0]), &((d + i)[1]));
		printf("%d\n", *(d + i));
	}

	// Allocating 2 d array of size [3 * 2]
	/* Type1:
	 * 	e[0] -> x1[2]
	 * 	e[1] -> x2[2]
	 * 	e[2] -> x3[2]
	 */
	e = (int **)malloc(sizeof(int*) * 3);
	for (i = 0; i< 3; i++) {
		e[i] = (int *) malloc(sizeof(int) * 2);
		for (j = 0; j < 2; j++) {
			e[i][j] = j;
			printf("e[%d][%d]:%d\n", i, j, e[i][j]);
		}
	}
}

// Return two d array as return value
int **return_2d_array() {
	int i, j;
	int **e = (int **)malloc(sizeof(int*) * 3);
	for (i = 0; i< 3; i++) {
		e[i] = (int *) malloc(sizeof(int) * 2);
		for (j = 0; j < 2; j++) {
			e[i][j] = j;
			printf("e[%d][%d]:%d\n", i, j, e[i][j]);
		}
	}
	return e;
}

// Return 2d array type 2 ??? - Failing
int **return_2d_array_type2() {
	int i, j;
	int *e = (int *)malloc(sizeof(int) * 2 * 3);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			*(e + (i * 3) + j) = j + 1;
		}
	}
	printf("Done\n");
	return (int **)e;
}

// Return 2d array type 3
int **return_2d_array_type3() {
	int i, j;
	int **e = (int **)malloc(sizeof(int *) * 2);
	int e[0] = (int *)malloc(sizeof(int) * 3 * 2);

	for (i = 0; i < 2; i++) {
	
}

int main() {
	int **x;
	int i, j;
	arrays_are_pointers();
	twod_arrays();
	x = return_2d_array();
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			printf("2d array %d\n", x[i][j]);
		}
	}
	x = return_2d_array_type2();
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			printf("2d array type2 %d\n", x[i][j]);
		}
	}
	return 0;
}
