#include "main.h"

/*
 * create_file - Crée un fichier.
 * @filename: Un pointeur vers le nom du fichier à créer.
 * @text_content: Un pointeur vers une chaîne de caractères à écrire dans le fichier.
 *
 * Retourne: Si la fonction échoue - -1.
 * Sinon - 1.
 */

int create_file(const char *filename, char *text_content)
{

	int df, wh, ln = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (ln = 0; text_content[ln];)
			ln++;
	}

	df = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wh = write(df, text_content, ln);

	if (df == -1 || wh == -1)
		return (-1);

	close(df);

	return (1);
}
