/*

░██████╗██╗███╗░░██╗░██████╗░██╗░░░░░██╗░░░██╗░░░░░░
██╔════╝██║████╗░██║██╔════╝░██║░░░░░╚██╗░██╔╝░░░░░░
╚█████╗░██║██╔██╗██║██║░░██╗░██║░░░░░░╚████╔╝░█████╗
░╚═══██╗██║██║╚████║██║░░╚██╗██║░░░░░░░╚██╔╝░░╚════╝
██████╔╝██║██║░╚███║╚██████╔╝███████╗░░░██║░░░░░░░░░
╚═════╝░╚═╝╚═╝░░╚══╝░╚═════╝░╚══════╝░░░╚═╝░░░░░░░░░
██╗░░░░░██╗███╗░░██╗██╗░░██╗███████╗██████╗░░░░░░░██╗░░░░░██╗░██████╗████████╗
██║░░░░░██║████╗░██║██║░██╔╝██╔════╝██╔══██╗░░░░░░██║░░░░░██║██╔════╝╚══██╔══╝
██║░░░░░██║██╔██╗██║█████═╝░█████╗░░██║░░██║█████╗██║░░░░░██║╚█████╗░░░░██║░░░
██║░░░░░██║██║╚████║██╔═██╗░██╔══╝░░██║░░██║╚════╝██║░░░░░██║░╚═══██╗░░░██║░░░
███████╗██║██║░╚███║██║░╚██╗███████╗██████╔╝░░░░░░███████╗██║██████╔╝░░░██║░░░
╚══════╝╚═╝╚═╝░░╚══╝╚═╝░░╚═╝╚══════╝╚═════╝░░░░░░░╚══════╝╚═╝╚═════╝░░░░╚═╝░░░

*/

#include "../includes/singly_linked_list.h"
#include <string.h>
#include <stdlib.h>

sll_headnode_t	new_list(void)
{
	sll_headnode_t	safe_list;

	safe_list.next = NULL;
	safe_list.tail = NULL;
	safe_list.length = 0;
	safe_list.size_in_bytes = 0;
	return (safe_list);
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