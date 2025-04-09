#include "sort.h"
#include <stdio.h>

/**
* insertion_sort_list-Sorts a doubly linked list of int use the Insertion sort
* @list: A pointer to the head of the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;

if (!list || !(*list) || !(*list)->next)
return;

current = (*list)->next;
while (current)
{
while (current->prev && current->n < current->prev->n)
{
/* Swap nodes */
temp = current->prev;
current->prev = temp->prev;
if (temp->prev)
temp->prev->next = current;
temp->next = current->next;
if (current->next)
current->next->prev = temp;
current->next = temp;
temp->prev = current;

/* If current is the head of the list, update the head */
if (!current->prev)
*list = current;

print_list(*list); /* Print the list after the swap */
}
current = current->next;
}
}
