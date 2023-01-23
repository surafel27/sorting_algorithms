#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *tmp2, *tmp3;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	tmp1 = (*list)->next;
	while (tmp1)
	{
		tmp2 = tmp1;
		while(tmp2->prev)
		{
			if(tmp2->n < tmp2->prev->n)
			{
				tmp3 = tmp2->prev;
				tmp3->next = tmp2->next;
				if(tmp3->next)
					tmp2->next->prev = tmp3;
				tmp2->next = tmp3;
				if(tmp3->prev)
					tmp3->prev->next = tmp2;
				tmp2->prev = tmp3->prev;
				tmp3->prev = tmp2;
				if(tmp2->prev == NULL)
					*list = tmp2;
				print_list(*list);
				continue;
			}
			tmp2 = tmp2->prev;
		}
		tmp1 = tmp1->next;
	}
}
