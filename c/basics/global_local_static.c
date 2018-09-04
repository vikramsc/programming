#include <stdio.h>

/*
 * Text Segment: code segment containing executable code (read-only)
 * Data Segment: (read-write)
 * 	Initialized: Global & Static variables initialized by program (DS)
 *			Const literals like const char *str = "hello world", the literal "hello world" stored here 			
 * 	Uninitialized: Global & Static variables uninitialized by program (bss, block started by Symbol)
 * 			Blocks in this segment initialized to 0 by Kernel
 * Stack: (LIFO Structure)
 * 	return variable and automatic variables are stored
 * Heap: Dynamic Memory allocation
 */

int global_uninit_a;	// Stored in bss (initialized to 0)
int global_a = 10;	// Stored in DS
extern int exter_a;	// Variables are stored in data segment, tells compiler dont create another instance of it as another compilation unit has done
			// other wise can cause name conflict during linking

static int static_uninit_a;	// Stored in bss (initialized to 0)
static int static_a;		// Stored in DS

void fun(int a, int b) {	// On function call a and b stored in stack
	static int local_static_a;	// Stored in bss (initialized to 0)
	static int local_a = 10;	// Stored in DS

	int s;			// Stored on stack (auto variables are intialized to 0)
	int *r;			// Stored on stack (address is not initialized, it contains arbitrary value, using this causes seg fault)

	const int x;		// constant variables value cannot be changed
	const int *y;		// pointer address cannot be changed, value pointed by address can be changed
}

static int fun1() {		// Static funcations restrict access of this method to same file
}

int main() {
	register int r;		// Store variable register in variable if possible otherwise in stack
	const int c = 10;	// Stored in DS(static) or stack(auto), but cannot modify value of c
	//c = 1;			// Not allowed
	volatile int x;		// Value can be changed by external entities like hardware so tell compiler not to optimize
}

