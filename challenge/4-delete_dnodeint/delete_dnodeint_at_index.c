#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int p;

    if (head == NULL || *head == NULL)
        return (-1);

    tmp = *head;
    p = 0;

    while (p < index)
    {
        if (tmp->next == NULL)
            return (-1);
        tmp = tmp->next;
        p++;
    }

    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    else
        *head = tmp->next;

    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    free(tmp);
    return (1);
}
