INCL	= slab_alloc.h
SRC	= slab_alloc.c test_sa.c
OBJ	= $(SRC:.c=.o)
EXE	= test_sa

CC	= "/usr/bin/gcc"
LDFLAGS	= -o $(EXE)
RM	= /bin/rm -f


# Compile and assemble c source files into object files
%.o:	%.c
	$(CC) -c $(CFLAGS) $*.c

# Link all object files with external libraries into binaries
$(EXE):	$(OBJ)
	$(CC) $(LDFLAGS) $(OBJ)

# Object depend on these libraries
$(OBJ): $(INCL)

# Create a debug binary
debug:
	$(CC) -g $(SRC)

# Cleanup objects
clean:
	$(RM) $(OBJ) $(EXE) core a.out

