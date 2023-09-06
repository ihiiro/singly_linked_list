#include "../includes/singly_linked_list.h"
#include <time.h>
#include <stdio.h>

int	main(void)
{
	sll_headnode_t	list;
	clock_t			start;
	int				tries;
	int				i;

	tries = 1000000;
	printf("Benchmark for singly linked list\n\n");
	i = 0;
	start = clock();
	while (i++ < tries)
		list = new_list();
	printf("new_list() (1,000,000 calls)\t\t\t\t\t%fs\n",
			((double)(clock() - start)) / CLOCKS_PER_SEC);
	i = 0;
	start = clock();
	while (i++ < tries)
		append(&list, "node");
	printf("append() (1,000,000 calls)\t\t\t\t\t%fs\n",
			((double)(clock() - start)) / CLOCKS_PER_SEC);
	i = 0;
	start = clock();
	while (i++ < tries)
		traverse(&list, NULL);
	printf("traverse() (traverse 1,000,000 nodes 1,000,000 times)\t\t%fs\n",
			((double)(clock() - start)) / CLOCKS_PER_SEC);
	i = 0;
	start = clock();
	free_sll(&list);
	printf("free_sll() (free 1,000,000 nodes)\t\t\t\t%fs",
			((double)(clock() - start)) / CLOCKS_PER_SEC);
}
