#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *outer, *inner, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	outer = (*list)->next;

	while (outer)
	{
		inner = outer;
		prev = inner->prev;
		while (inner && prev && prev->n > inner->n)
		{
			swap_nodes(list, prev, inner);
			prev = inner->prev;
			print_list(*list);
		}
		outer = outer->next;
	}
}

/**
 * swap_nodes - Swaps a node with the node before it in a doubly linked list.
 * @head: Pointer to the head of the list.
 * @prevNode: Pointer to the node before the node to be swapped.
 * @node: Pointer to the node to be swapped with the node before it.
 */
void swap_nodes(listint_t **head, listint_t *prevNode, listint_t *node)
{
	listint_t *nextNode;

	if (head == NULL || *head == NULL || prevNode == NULL || node == NULL)
		return;

	nextNode = node->next;

	if (prevNode->prev)
		prevNode->prev->next = node;
	else
		*head = node;

	if (nextNode)
		nextNode->prev = prevNode;

	node->prev = prevNode->prev;
	prevNode->prev = node;
	prevNode->next = nextNode;
	node->next = prevNode;
}
