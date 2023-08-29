#include "./singly_linked_list.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putstr(sll node)
{
	int	i;

	i = 0;
	while (node.payload[i])
	{
		write(1, &node.payload[i], 1);
		i++;
	}
}

int	count = 0;
void	counter()
{
	count++;
}

int	main(void)
{
	sll	list;

	list.payload = NULL;
	list.next = NULL;

	// count should be 1 because there is 1 empty node initially
	traverse(list, counter);
	printf("%d\n", count);

	// count should be 2 because we appended a node
	traverse(list, counter);
	traverse(list, counter);
	traverse(list, counter);
	append(&list, "new node");
	traverse(list, counter);
	printf("%d", count);
}
