/*
 * Generic Slab Allocator
 *
 * Slab allocator for any type of data
 */
#ifndef _SLAB_ALLOC_H
#define _SLAB_ALLOC_H 1

#define SIZEOF(type)	((char *)(&type + 1) - (char *)(&type))
#define SIZEOF_TYPE(T)	((T*)0 + 1) - ((T*)0)

typedef struct {
	int n;
	char *buffer;
} bits_t;

typedef struct {
	int nelems;
	int size;
	bits_t *bits;
	char *buffer;
} slab_alloc_t;

/* Initilaize/Deinitlize slab allocator */
extern slab_alloc_t *sa_init(int nelems, int size);
extern void sa_close(slab_alloc_t *sa);

extern void* sa_alloc(slab_alloc_t *sa);
extern void sa_free(slab_alloc_t *sa, void *elem);

#endif /* SLAB_ALLOC_H */


