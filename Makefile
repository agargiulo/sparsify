CFLAGS = -ggdb -std=c99 -Wall -Wextra

BINARIES = sparsify sparsify.o

all: sparsify

sparsify.o: sparsify.c
	$(CC) $(CFLAGS) -c $^

sparsify: sparsify.o
	$(CC) $(CFLAGS) -o sparsify $^

clean:
	@$(RM) -rfv $(BINARIES)
