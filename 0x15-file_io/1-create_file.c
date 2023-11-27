#include "main.h"
#include <stdlib.h>
#include <stdio>

/*
 *Create a function that creates a file.
 *Prototype: int create_file(const char *filename, char *text_content);
 *where filename is the name of the file to create and text_content is a NULL terminated string to write to the file
 *Returns: 1 on success, -1 on failure (file can not be created, file can not be written, write “fails”, etc…)
 *The created file must have those permissions: rw-------. If the file already exists, do not change the permissions.
 *if the file already exists, truncate it
 *if filename is NULL return -1
 *if text_content is NULL create an empty file
 */
 
int create_file(const char *filename, char *text_content)
{
	int df,len = 0, w;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	df = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(df, text_content, len);

	if (df == -1 || w == -1)
		return (-1);

	close(df);

	return (1);

}
