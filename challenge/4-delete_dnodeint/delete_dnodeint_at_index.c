#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    dlistint_t *tmp;
    unsigned int p;

    if (*head == NULL)
        return (-1);

    saved_head = *head;
    p = 0;
    while (p < index && tmp != NULL)
    {
        tmp = tmp->next;
        p++;
    }
    if (tmp == NULL)
        return (-1);

    if (index == 0)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(tmp);
    }
    else
    {
        tmp->prev->next = tmp->next;   /* nodo anterior apunta al siguiente */
        if (tmp->next != NULL)
            tmp->next->prev = tmp->prev; /* nodo siguiente apunta al anterior */
        free(tmp);                      /* ahora sí liberamos */
    }
    return (1);
}
