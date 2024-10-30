#include <stdio.h>
#include "sort.h"

/**
  *swaps_nodes -Swaps two nodes in a listint_t doubly-linked list.
  *@h: pointer to the head of the doubly linked list
  *@n1: pointer to the first node to swap
  *@n2: The second node to swap
  */

void swaps_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
	{
		n2->next->prev = *n1;
	}
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
	{
		(*n1)->prev->next = n2;
	}
	else
	{
		*h = n2;
	}
	(*n1)->prev = n2;
	*n1 = n2->prev;
}




/**
 *insertion_sort_list - Sorts a doubly linked list of integers
 *using the insertion sort method.
 *@list: double pointer to the head of the
 *doubly linked list of integers.
 *
 *Description: Displays the list after each node swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		prev_node = current->prev;
		while (prev_node != NULL && current->n < prev_node->n)
		{
			swaps_nodes(list, &prev_node, current);
			print_list((const listint_t *)*list);
		}
	}
}
