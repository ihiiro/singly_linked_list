#ifndef SINGLY_LINKED_LIST_H
# define SINGLY_LINKED_LIST_H

typedef struct	sll_t
{
	char			*payload;
	struct sll_t	*next;
}	sll_t;

typedef struct  sll_headnode_t
{
	sll_t			*next;
	sll_t			*tail;
	int				length;
	int				size_in_bytes;
}	sll_headnode_t;

sll_headnode_t	new_list(void);
void			traverse(sll_headnode_t *list, void (*process)(sll_t *));
void			append(sll_headnode_t *list, char *payload);
void			free_sll(sll_headnode_t *list);

#endif
