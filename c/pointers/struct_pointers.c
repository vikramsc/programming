#include <stdio.h>
#include <malloc.h>

typedef struct mystruct {
	int a;
	int b;
	struct mystruct *self;
} MyStruct;

typedef enum myenum {
	red = 0, green, blue, orange
} MyEnum;

typedef enum notmyenum {
	purple=100, indigo
} NotMyEnum;

int main() {
	MyStruct m;
	MyEnum e = purple;	// Cannot differentiate between which type of enum
	MyEnum f = red;

	m.a = 10;
	m.b = 11;
	m.self = &m;

	printf("%d\n", e);
}

	
	
