#ifndef SINGLY_LINKED_LIST_H
# define SINGLY_LINKED_LIST_H

# define INFINITY 1
# define NULL 0
# define NULL_STRING ""

typedef struct  sll_t
{
	struct sll_t	*next;
	char			*payload;
	int				length;
}	sll_t;

void	traverse(sll_t list, void (*process)(sll_t));
void	append(sll_t *list, char *payload);
sll_t	new_list();

#endif
