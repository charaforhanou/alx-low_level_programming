/**
 * malloc_checked - Allocates memory using malloc
 * @b: Size of memory to allocate
 *
 * Return: Pointer to allocated memory, or exit with status 98 if allocation fails
 */
void *malloc_checked(unsigned int b)
{
    void *ptr;

    ptr = malloc(b);
    if (ptr == NULL)
    {
        exit(98);
    }
    else
    {
        return (ptr);
    }
}

