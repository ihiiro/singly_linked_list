#include "./singly_linked_list.h"
#include <stdlib.h>
#include <string.h>

void	traverse(sll_t *list, void (*process)(sll_t *))
{
	sll_t	*node;

	if (process == NULL)
		return;
	node = list;
	while (node)
	{
		process(node);
		node = node->next;
	}
}

void	append(sll_t *list, char *payload)
{
	sll_t	*node;
	sll_t	*new_node;
	int		payload_size;
	int		sll_t_size;

	node = list;
	payload_size = strlen(payload) + 1;
	sll_t_size = sizeof(sll_t);
	while (node->next)
	{
		node = node->next;
	}
	new_node = (sll_t *)malloc(sll_t_size);
	new_node->payload = (char *)malloc(payload_size);
	strcpy(new_node->payload, payload);
	new_node->next = NULL;
	new_node->length = 0;
	new_node->size_in_bytes = 0;
	node->next = new_node;
	list->length++;
	list->size_in_bytes += sll_t_size +
			payload_size;
}

sll_t	new_list()
{
	sll_t	safe_list;

	safe_list.payload = "HEAD NODE";
	safe_list.next = NULL;
	safe_list.length = 1;
	safe_list.size_in_bytes = sizeof(sll_t) +
			strlen(safe_list.payload) + 1;
	return (safe_list);
}

void	free_sll(sll_t *list)
{
	sll_t	*next_head;

	list = list->next;
	while (list)
	{
		next_head = list->next;
		free(list->payload);
		free(list);
		list = next_head;
	}
}
