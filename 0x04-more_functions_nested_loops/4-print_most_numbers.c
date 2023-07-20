#include "main.h"
/*
 *Prototype: void print_most_numbers(void);
Do not print 2 and 4
You can only use _putchar twice in your code
*/
void print_most_numbers(void)
{
for (i=0;i<10;i++)
{
if (i!=2 || i!=4)
printf("%d",i);
}
printf("\n");

return 0 ;
