#include "./singly_linked_list.h"

void	traverse(sll list, int (*process)(sll))
{
	sll	node;

	node = list;
	while (INFINITY)
	{
		process(node);
		if (node.next == NULL)
			break;
		node = *node.next;
	}
}
