# Singly Linked List
Memory safety: excerpt from valgrind output:
```
==4699== HEAP SUMMARY:
==4699==     in use at exit: 0 bytes in 0 blocks
==4699==   total heap usage: 9 allocs, 9 frees, 1,166 bytes allocated
==4699==
==4699== All heap blocks were freed -- no leaks are possible
```

## API
```c
void	traverse(sll_t *list, void (*process)(sll_t *))
```
traverses the list, applying `process` to each node.

```c
void	append(sll_t *list, char *payload)
```
appends a new node to the list.

```c
sll_t	new_list()
```
list constructor, here for your own safety, returns an sll_t with only the head node.

```c
void	free_sll(sll_t *list)
```
frees the entire list.
