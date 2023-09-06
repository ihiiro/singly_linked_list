/*
	Implementation of a singly linked list in c.
	By: Yassir Elyaqine (ihiiro) in 2023
	Email: yassirelyakine@gmail.com
*/

#include "../includes/singly_linked_list.h"
#include <stdlib.h>
#include <string.h>

void	traverse(sll_headnode_t *list, void (*process)(sll_t *))
{
	sll_t	*node;

	if (process == NULL)
		return;
	node = list->next; // skip headnode
	while (node)
	{
		process(node);
		node = node->next;
	}
}

void	append(sll_headnode_t *list, char *payload)
{
	sll_t	*new_node;
	int		payload_size;
	int		sll_t_size;

	payload_size = strlen(payload) + 1;
	sll_t_size = sizeof(sll_t);
	new_node = (sll_t *)malloc(sll_t_size);
	new_node->payload = (char *)malloc(payload_size);
	strcpy(new_node->payload, payload);
	new_node->next = NULL;
	if (!list->tail)
	{
		list->tail = new_node;
		list->next = new_node;
	}
	else
	{
		list->tail->next = new_node;
		list->tail = new_node;
	}
	list->length++;
	list->size_in_bytes += sll_t_size + payload_size;
}

sll_headnode_t	new_list(void)
{
	sll_headnode_t	safe_list;

	safe_list.next = NULL;
	safe_list.tail = NULL;
	safe_list.length = 1;
	safe_list.size_in_bytes = sizeof(sll_headnode_t);
	return (safe_list);
}

void	free_sll(sll_headnode_t *list)
{
	sll_t	*next_head;
	sll_t	*traverser;

	traverser = list->next; // skip headnode (not in heap)
	while (traverser)
	{
		next_head = traverser->next;
		free(traverser->payload);
		free(traverser);
		traverser = next_head;
	}
}
