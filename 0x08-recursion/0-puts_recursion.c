#include "main.h"
/**
 *
 *  _put_recursion(char *s
 *  return : void
 *
 *pointr=er to the string
 *
 *
 *
 * */
void _put_recursion(char *s)
{
	if (*s == '\0')
	{

		_putchar('\n');	
	}
	else
	{
		putchar(*s);
		_puts_recursion(s + 1);
	
	}


}
