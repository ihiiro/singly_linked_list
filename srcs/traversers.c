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
Author: Hiro (ihiiro)
Email: yassirelyakine@gmail.com
License: MIT
Start: 2023
Update: 2023

*/

#include "../includes/singly_linked_list.h"
#include <stdlib.h>

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
	list->length = 0;
	list->size_in_bytes = 0;
	list->tail = NULL;
	list->next = NULL;
}