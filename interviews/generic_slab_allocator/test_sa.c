#include <stdio.h>
#include "slab_alloc.h"
#include <malloc.h>

typedef struct {
	int a;
	int b;
} test_t;

int main() {
	slab_alloc_t *a = sa_init(10, SIZEOF_TYPE(test_t));
	int i = 0, j;
	test_t *t;

	for (i = 0; i < 16; i++) {
		test_t *t = (test_t *)sa_alloc(a);
		if (t == NULL) {
			printf("Failed\n");
			return -1;
		}
	}
}
