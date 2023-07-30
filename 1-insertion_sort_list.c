#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - sorts a list of integers
 * in ascending order.
 *
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *tmp, *tmpPrev;
	listint_t *tmp2, *tmpPrev2, *tmpNext2, *tmpPrevPrev2;

	if (list == NULL)
		return;
	while (temp != NULL)
	{
		tmp = temp;
		tmpPrev = temp->prev;
		if (tmpPrev != NULL && tmp->n < tmpPrev->n)
		{
			tmp2 = temp;
			tmpPrev2 = temp->prev;
			while (tmpPrev2 != NULL && temp->n < temp->prev->n)
			{
				tmp2 = temp;
				tmpPrev2 = temp->prev;
				tmpNext2 = temp->next;
				tmpPrevPrev2 = temp->prev->prev;

				if(tmpNext2 != NULL)
					temp->next->prev = tmpPrev2;
				if (tmpPrevPrev2 != NULL)
					temp->prev->prev->next = tmp2;

				temp->prev->next = tmp2->next;
				temp->prev = tmpPrev2->prev;
				tmpPrev2->prev = tmp2;
				temp->next = tmpPrev2;

				if (temp->prev == NULL)
					*list = temp;

				tmpPrev2 = temp->prev;
				print_list(*list);
			}
		}
		temp = tmp->next;
	}
}
