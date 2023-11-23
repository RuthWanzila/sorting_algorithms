#include "sort.h"

/**
* swap - Swaps two elements in a doubly linked list
* @a: First node to be swapped
* @b: Second node to be swapped
* @head: Pointer to the head of the list
*
* Swaps the positions of two nodes in a doubly linked list.
*/
void swap(listint_t *a, listint_t *b, listint_t **head)
{
listint_t *prev_a = NULL, *next_a = NULL;
listint_t *prev_b = NULL, *next_b = NULL;

if (a == NULL || b == NULL)
return;

prev_a = a->prev;
next_a = a->next;
prev_b = b->prev;
next_b = b->next;

if (prev_a)
prev_a->next = b;
if (next_a)
next_a->prev = b;
if (prev_b)
prev_b->next = a;
if (next_b)
next_b->prev = a;

a->next = next_b;
a->prev = prev_b;
b->next = next_a;
b->prev = prev_a;

if (prev_a == NULL)
*head = b;
}

/**
* insertion_sort_list - Sorts a doubly linked list in ascending order
* using the insertion sort algorithm
* @list: Pointer to the head of the list
*
* Sorts the list in place using the insertion sort algorithm.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *head, *prev;
int value;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

head = *list;

while (head)
{
prev = head->prev;
value = head->n;

while (prev && prev->n > value)
{
swap(prev, head, list);
print_list(*list);
prev = head->prev;
}

head = head->next;
}
}
