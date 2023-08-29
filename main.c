#include "./singly_linked_list.h"
#include <unistd.h>

int	ft_putstr(sll node)
{
	int	i;

	i = 0;
	while (node.payload[i])
	{
		write(1, &node.payload[i], 1);
		i++;
	}
	return (1);
}

int	main(void)
{
	sll	list;
	sll	second;

	list.payload = "yassir";
	list.next = &second;
	second.payload = " elyakine";
	second.next = NULL;
	traverse(list, ft_putstr);
	return (0);
}
