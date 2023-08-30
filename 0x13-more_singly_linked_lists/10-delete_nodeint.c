#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index of a listint_t list
 * @head: Pointer to a pointer to the head node of the list
 * @index: Index of the node to be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    if (*head == NULL)
        return (-1);

    if (index == 0)
    {
        listint_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return (1);
    }

    listint_t *prev_node = NULL;
    listint_t *current_node = *head;
    unsigned int current_index = 0;

    while (current_node != NULL && current_index < index)
    {
        prev_node = current_node;
        current_node = current_node->next;
        current_index++;
    }

    if (current_node == NULL)
        return (-1);

    prev_node->next = current_node->next;
    free(current_node);

    return (1);
}

