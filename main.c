#include "./singly_linked_list.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putstr(sll_t node)
{
	int	i;

	i = 0;
	write(1, "\r\t\t", 3);
	while (node.payload[i])
	{
		write(1, &node.payload[i], 1);
		i++;
	}
	if (node.payload[0] && node.next)
		write(1, "\n\n", 2);
}

int	main(void)
{
	sll_t	list = new_list();

	printf("initial state: [%d node] [%d bytes].\n\n", list.length,
			list.size_in_bytes);
	append(&list, "FIRST NODE");
	append(&list, "SECOND NODE");
	append(&list, "THIRD NODE");
	printf("after appending 3 nodes: [%d nodes] [%d bytes].\n\n",
			list.length, list.size_in_bytes);
	printf("traversing...\n\n");
	traverse(list, ft_putstr);
}
