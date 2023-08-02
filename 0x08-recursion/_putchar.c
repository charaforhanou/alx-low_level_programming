#include <unistd.h>
/**
 * putchar  take a caractere and printed for you
 *
 *
 *
 *
 * */
int  _putchar(char c)
{
	return (write(1, &c, 1));
}
