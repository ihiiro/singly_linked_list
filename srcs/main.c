/*
	Implementation of a singly linked list in c.
	My github: https://github.com/ihiiro
*/

#include "../includes/singly_linked_list.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putstr(sll_t *node)
{
	int	i;

	i = 0;
	write(1, "\r\t\t", 3);
	while (node->payload[i])
	{
		write(1, &node->payload[i], 1);
		i++;
	}
	if (node->payload[0] && node->next)
		write(1, "\n\n", 2);
}

int	main(void)
{
	sll_headnode_t	list;

	list = new_list();
	printf("initial state: [%d node] [%d bytes].\n\n", list.length,
			list.size_in_bytes);
	append(&list, "FIRST NODE");
	append(&list, "SECOND NODE");
	append(&list, "THIRD NODE");
	append(&list, "FOURTH NODE");
	printf("after appending 4 nodes: [%d nodes] [%d bytes].\n\n",
			list.length, list.size_in_bytes);
	printf("traversing...\n\n");
	traverse(&list, ft_putstr);
	printf("\n\nfreeing...");
	free_sll(&list);
	printf("done.");

	printf("\n\n%d", list.size_in_bytes);
}
