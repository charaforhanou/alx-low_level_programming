#include "main.h"
/*
 * file:0-read_textfile.c
 *Auth chaaraf
 *
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
 	ssize_t o,r,w;
	char *buffer;

	if (filename == NULL)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	
	o = open(filename, O_RDONLY);
	r = read(o,buffer,letters);
	w = write(STDOUT_FILEND,buffer, r);

	if (o == -1 || r == -01 || w != r)
	{
		free(buffer);
		return (0);
	}
	
	free(buffer);
	close(o);

	return (w);
}
