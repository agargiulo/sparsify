#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s old_file new_file\n", argv[0]);
		return(EXIT_FAILURE);
	}

	char *old_fi_name;
	char *new_fi_name;
	int old_file;
	int new_file;
	off_t old_fi_size = 0;
	struct stat old_fi_stats;

	old_fi_name = argv[1];
	new_fi_name = argv[2];

	if ((old_file = open(old_fi_name, O_RDONLY)) == -1)
	{
		perror(old_fi_name);
		return EXIT_FAILURE;
	}

	stat(old_fi_name, &old_fi_stats);
	old_fi_size = old_fi_stats.st_size;

	if ((new_file = open(new_fi_name, O_RDWR | O_CREAT, old_fi_stats.st_mode)) == -1)
	{
		perror(new_fi_name);
		return EXIT_FAILURE;
	}

	if (ftruncate(new_file, old_fi_size) == -1)
	{
		perror(new_fi_name);
		return EXIT_FAILURE;
	}

	if (close(old_file) == -1)
	{
		perror(old_fi_name);
		return EXIT_FAILURE;
	}

	if (close(new_file) == -1)
	{
		perror(new_fi_name);
		return EXIT_FAILURE;
	}

	printf("Size of old file (%s): %li bytes\n", old_fi_name, old_fi_size);
	return EXIT_SUCCESS;
}
