#include "./singly_linked_list.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putstr(sll_t node)
{
	int	i;

	i = 0;
	while (node.payload[i])
	{
		write(1, &node.payload[i], 1);
		i++;
	}
	if (node.payload[0] && node.next)
		write(1, ", ", 2);
}

int	main(void)
{
	sll_t	list = new_list();

	printf("initial state length: %d nodes.\n\n", list.length);
	append(&list, "first node");
	append(&list, "second node");
	append(&list, "third node");
	printf("after appending 3 nodes: %d nodes.\n\n", list.length);
	traverse(list, ft_putstr);
}
