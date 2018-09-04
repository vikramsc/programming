#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nchar(s,n) (s[n])

void method() {
	char *a = "hello";
	char *b = "world";
	char *c[3] = { a, b, 0};
	printf("%d%d\n", strlen (a), strlen(*a));
	printf("%c %c %c %c\n", c[0][1], c[1][0], *c[0], *b);
		
}
int main() {
	char *s = "hello";
	char *r = "world";
	char x[] = "aaaaa0\0zzzzz";
	printf("len: %d\n", sizeof (x));
	int a[] = {1, 2, 3, 4};
	printf("%c%c", nchar(s,1), nchar(r,2));
	printf("%d", nchar(a, 3));
	method();
	return 1;
}

