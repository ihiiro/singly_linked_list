#include "./singly_linked_list.h"
#include <stdlib.h>
#include <string.h>

void	traverse(sll_t list, void (*process)(sll_t))
{
	sll_t	node;

	if (process == NULL)
		return;
	node = list;
	while (INFINITY)
	{
		process(node);
		if (node.next == NULL)
			break;
		node = *node.next;
	}
}

void	append(sll_t *list, char *payload)
{
	sll_t	*node;
	sll_t	*new_node;

	node = list;
	while (INFINITY)
	{
		if (node->next == NULL)
		{
			new_node = (sll_t *)malloc(sizeof(sll_t));
			new_node->payload = (char *)malloc(strlen(payload) + 1);
			strcpy(new_node->payload, payload);
			new_node->next = NULL;
			node->next = new_node;
			break;
		}
		node = node->next;
	}
	list->length++;
}

sll_t	new_list()
{
	sll_t	safe_list;

	safe_list.payload = NULL_STRING;
	safe_list.next = NULL;
	safe_list.length = 0;
	return (safe_list);
}
