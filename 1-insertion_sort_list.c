#include "sort.h"

/**
 * node_change - changes the next node for the previous one
 * @list1: list1
 * @listt: list2
 * @list: doubly linked list
 *
 * Return: void
 */
void node_change(listint_t **list1, listint_t **listt, listint_t **list)
{
	listint_t *previous;
	listint_t *next_one;

	if (!(*list1) || !(*listt))
		return;
	previous = (*list1)->prev;
	next_one = (*listt)->next;

	if (previous)
		previous->next = (*listt);

	(*listt)->prev = previous;
	(*listt)->next = (*list1);
	(*list1)->prev = (*listt);
	(*list1)->next = next_one;

	if (next_one)
		next_one->prev = (*list1);

	*list1 = *listt;
	*listt = (*list1)->next;

	if (!next_one)
		*list = *list1;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL;
	listint_t *node = NULL;
	listint_t *tmp = NULL;

	if (!list || (!((*list)->prev) && !((*list)->next)))
		return;
	head = *list;
	head = head->next;

	while (head)
	{
		node = head->prev;
		if (node->n > head->n)
		{
			node_change(&node, &head, list);
			print_list(*list);
			while (node->prev)
			{
				if ((node->n) < (node->prev->n))
				{
					tmp = node->prev;
					node_change(&tmp, &node, list);
					print_list(*list);
				}
				node = node->prev;
			}
		}
		head = head->next;
	}
}
