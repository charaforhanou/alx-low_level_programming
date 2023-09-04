// create_file.c

#include "main.h"
#include <fcntl.h>
#include <unistd.h>

int create_file(const char *filename, char *text_content) {
    if (filename == NULL)
        return (-1);

    int file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

    if (file_descriptor == -1)
        return (-1);

    if (text_content != NULL) {
        ssize_t text_length = 0;
        while (text_content[text_length])
            text_length++;

        ssize_t bytes_written = write(file_descriptor, text_content, text_length);

        if (bytes_written == -1) {
            close(file_descriptor);
            return (-1);
        }
    }

    close(file_descriptor);
    return (1);
}

