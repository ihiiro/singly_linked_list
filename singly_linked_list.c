#include "./singly_linked_list.h"
#include <stdlib.h>
#include <string.h>

void	traverse(sll list, void (*process)(sll))
{
	sll	node;

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

void	append(sll *list, char *payload)
{
	sll	*node;
	sll	*new_node;

	node = list;
	while (INFINITY)
	{
		if (node->next == NULL)
		{
			new_node = (sll *)malloc(sizeof(sll));
			new_node->payload = (char *)malloc(strlen(payload) + 1);
			strcpy(new_node->payload, payload);
			new_node->next = NULL;
			node->next = new_node;
			break;
		}
		node = node->next;
	}
}
