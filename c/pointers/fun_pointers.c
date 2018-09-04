#include<stdio.h>
#include<malloc.h>

void fun(int a, int b);
int *fun1(int *a, int *b);

void fun(int a, int b) {
	printf("%d %d\n", a, b);
}

int *fun1(int *a, int *b) {
	int *c = (int*)malloc(sizeof(int));
	*c = *a + *b;
	return c;
}

int main() {
	void (*fun_ptr)(int, int) = &fun;
	int *(*fun1_ptr)(int *, int*) = &fun1;
	int a = 10, b = 20, *c;
	(*fun_ptr)(1, 2);
	c = (*fun1_ptr)(&a, &b);
	printf("%d %d = %d\n", a, b, *c);
}
