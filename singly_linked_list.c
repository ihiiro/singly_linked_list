#include "./singly_linked_list.h"
#include <stdio.h>

int main(void)
{
	sll	singly_linked_list;
	sll	traverser;

	sll	next;
	next.payload = " World!";
	next.next = 0;
	singly_linked_list.payload = "Hello,";
	singly_linked_list.next = &next;
	traverser = singly_linked_list;
	while (INFINITY)
	{
		printf("%s", traverser.payload);
		if (!traverser.next)
			break;
		traverser = *traverser.next;
	}
}
