#ifndef SINGLY_LINKED_LIST_H
# define SINGLY_LINKED_LIST_H

# define INFINITY 1
# define NULL 0

typedef struct  sll
{
	char			*payload;
  	struct sll		*next;
}	sll;

void	traverse(sll list, int (*process)(sll));

#endif
