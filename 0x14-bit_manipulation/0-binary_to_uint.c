#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int.
 *
 * @b: pointing to a string
 *
 * Return: the converted number, or 0 if
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num;
	int x, ban;

	if (b == NULL)
	{
		return (0);
	}

	for (num = 0, ban = 0, x = 0; b[x] != '\0'; x++)
	{
		if (b[x] != '1' && b[x] != '0')
			return (0);
		if (!ban && b[x] == '1')
			ban = 1;
		if (ban && b[x] == '1')
			num = num << 1, num += 1;
		else if (ban && b[x] == '0')
			num = num << 1;
	}
	return (num);

}
