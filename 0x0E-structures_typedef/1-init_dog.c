#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initializes a variable for type struct dog
 * @d: pointer to struct dog for  initialisation
 * @name: name to initialisation
 * @age: age to initialisation
 * @owner: owner to initialisation
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}

