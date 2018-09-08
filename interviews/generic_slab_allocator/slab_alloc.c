#include <malloc.h>
#include "slab_alloc.h"

slab_alloc_t *sa_init(int nelems, int size) {
	int n = (nelems / 8) + (nelems % 8 != 0);
	slab_alloc_t *a = (slab_alloc_t*)malloc(sizeof(slab_alloc_t));
	a->nelems = nelems;
	a->size = size;
	a->bits = (bits_t*)malloc(sizeof(bits_t));
	a->bits->n = n;
	a->bits->buffer = (char *)calloc(sizeof(char), n);
	a->buffer = (void *)malloc(nelems * size);
	return a;
}

void sa_close(slab_alloc_t *sa) {
	if (sa != NULL) {
		free(sa->bits->buffer);
		free(sa->buffer);
		free(sa);
	}
}

// Locking required here
int alloc_slot(bits_t *bits) {
	int i, j;
	char *c;
	if (bits == NULL) {
		return -1;
	}

	for (i = 0; i < bits->n; i++) {
		c = bits->buffer + i;
		if (*c == 0xff) {
			continue;
		}
		for (j = 0; j < 8; j++) {
			if (*c & (1 << j)) {
				continue;
			} else {
				*c = *c | (1 << j);
				return (i * 8 + j);
			}
		}
	}
	return -1;
}

// Locking required
void free_slot(bits_t *bits, int slot_index) {
	int i = slot_index / 8;
	char *c;
	int j = slot_index % 8;

	if (bits == NULL || slot_index < 0 || slot_index > bits->n) {
		return;
	}
	c = bits->buffer + i;
	*c = *c ^ (1 << j);
	return;
}
void *sa_alloc(slab_alloc_t *sa) {
	int free_slot_index = alloc_slot(sa->bits);
	if (free_slot_index == -1) {
		return NULL;
	}
	return (void *)(sa->buffer + (sa->size * free_slot_index));
}

void sa_free(slab_alloc_t *sa, void *elem) {
	int index = ((sa->buffer - (char *)elem) / sa->size);
	free_slot(sa->bits, index);
}
