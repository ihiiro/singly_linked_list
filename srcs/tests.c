/*
	Implementation of a singly linked list in c.
	My github: https://github.com/ihiiro
*/

#include "../includes/singly_linked_list.h"
#include <assert.h>
#include <string.h>

int	counter = 0;
int	g_list_length = 2;
void	count(sll_t *node)
{
	node = node;
	counter++;
}

int	main(void)
{
	sll_headnode_t	list;

	// TESTS FOR new_list()
	list = new_list();
	assert(list.next == NULL);
	assert(list.tail == NULL);
	assert(list.length == 0);
	assert(list.size_in_bytes == 0);
	// TESTS FOR append()
	append(&list, "four");
	append(&list, "four+2");
	assert(strlen(list.next->payload) == 4);
	assert(strlen(list.tail->payload) == 6);
	assert(strlen(list.next->next->payload) == 6);
	assert(list.next->next->next == NULL);
	assert(list.tail->next == NULL);
	assert(list.length == g_list_length);
	assert(list.size_in_bytes > 0);
	// TESTS FOR traverse()
	traverse(&list, count);
	assert(counter == g_list_length);
	// TESTS FOR free_sll()
	free_sll(&list);
	assert(list.next == NULL);
	assert(list.tail == NULL);
	assert(list.length == 0);
	assert(list.size_in_bytes == 0);
}
