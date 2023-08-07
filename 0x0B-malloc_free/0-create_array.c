#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates array of chars.
 * @size: size of array.
 * @c: storaged char
 *
 * Return: pointer of an array of chars
 */
char *create_array(unsigned int size, char c)
{
	char *ce;
	unsigned int i;

	if (size == 0)
		return (NULL);

	ce = malloc(sizeof(c) * size);

	if (ce== NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		ce[i] = c;

	return (ce);
}
