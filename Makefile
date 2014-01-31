CC = clang
CFLAGS = -ggdb -std=c99 -Wall -Wextra

BINARIES = sparsify

all: sparsify

sparsify: sparsify.c
	$(CC) $(CFLAGS) -o stringParse $^

clean:
	@$(RM) -rfv $(BINARIES)

