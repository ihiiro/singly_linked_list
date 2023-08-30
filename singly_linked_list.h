#ifndef SINGLY_LINKED_LIST_H
# define SINGLY_LINKED_LIST_H

# define INFINITY 1
# define NULL 0

typedef struct  sll_t
{
	char			*payload;
	int				length;
	int				size_in_bytes;
	struct sll_t	*next;
}	sll_t;

void	traverse(sll_t list, void (*process)(sll_t));
void	append(sll_t *list, char *payload);
sll_t	new_list();

#endif
