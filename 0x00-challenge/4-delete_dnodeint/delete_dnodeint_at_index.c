#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head, *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}

	saved_head = *head;
	p = 0;

	if (index == 0)
	{
		tmp = (*head)->next;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
		free(*head);
		*head = tmp;
		return (1); // Return success
	}

	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}

	if (p != index)
	{
		*head = saved_head;
		return (-1); // Node at the specified index not found
	}
	else
	{
		tmp = *head;
		(*head)->prev->next = (*head)->next;

		if ((*head)->next != NULL)
		{
			(*head)->next->prev = (*head)->prev;
		}

		free(tmp);
		*head = saved_head;
		return (1); // Return success
	}
}
