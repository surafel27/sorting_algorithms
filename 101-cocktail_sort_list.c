#include <stdbool.h>
#include "sort.h"
/**
 * swap - function used to swap doubly linked list
 * @current: the current of the list
 * @nxt: the next to be swaped
 * @list: the list to be swaped
 */
void swap(listint_t *current, listint_t *nxt, listint_t **list)
{
	if (current->prev == NULL)
	{
		current->next = nxt->next;
		if (nxt->next)
			nxt->next->prev = current;
		nxt->next = current;
		nxt->prev = NULL;
		current->prev = nxt;
		*list = nxt;
	}
	else
	{
		nxt->prev->next = nxt->next;
		if (nxt->next)
			nxt->next->prev = current;
		current->prev->next = nxt;
		nxt->prev = current->prev;
		current->prev = nxt;
		nxt->next = current;
	}
}
/**
 * cocktail_sort_list - fuction sort forward then backward
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *nxt;
	bool swpd = true;

	if ((*list) == NULL || !(*list) || (*list)->next == NULL)
		return;
	nxt = (*list);
	while (swpd)
	{
		swpd = false;
		while (nxt->next != NULL)
		{
			if (nxt->next != NULL && nxt->n > nxt->next->n)
			{
				swap(nxt, nxt->next, list);
				print_list((*list));
				swpd = true;
				continue;
			}
			nxt = nxt->next;
		}
		nxt = nxt->prev;
		while (nxt->prev != NULL)
		{
			if (nxt->prev != NULL && nxt->n < nxt->prev->n)
			{
				swap(nxt->prev, nxt, list);
				print_list((*list));
				swpd = true;
				continue;
			}
			nxt = nxt->prev;
		}
		nxt = nxt->next;
	}
}
