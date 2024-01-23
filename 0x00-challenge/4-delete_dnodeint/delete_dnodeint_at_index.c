#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a given position in a doubly linked list.
 * @head: Pointer to the head of the doubly linked list.
 * @index: Index of the node to delete.
 *
 * Return: 1 if successful, -1 if an error occurred.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return -1;

	current = *head;
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return 1;
	}

	for (i = 0; i < index - 1; i++)
	{
		if (current == NULL)
			return -1;
		current = current->next;
	}

	if (current == NULL || current->next == NULL)
		return -1;

	temp = current->next;
	current->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = current;
	free(temp);

	return 1;
}