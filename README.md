# Singly Linked List

## Memory safety: excerpt from valgrind output:
```
==4699== All heap blocks were freed -- no leaks are possible
```

## Executable ran on:
Operating System: Kali GNU/Linux Rolling x86_64

Hostname: HP 255 G3 Notebook PC

Kernel: 6.4.0-kali3-amd64

Shell: zsh 5.9

CPU: AMD E1-2100 APU (2 cores) @ 1.0 GHz

GPU: AMD ATI Radeon HD 8210

Memory: 3364 MiB total

```
Benchmark for singly linked list

new_list() (1,000,000 calls)                                    0.033304s
append() (1,000,000 calls)                                      0.473783s
traverse() (traverse 1,000,000 nodes 1,000,000 times)           0.015447s
free_sll() (free 1,000,000 nodes)                               0.134713s  
```

## API
```c
void	traverse(sll_headnode_t *list, void (*process)(sll_t *));
```
traverses the list, applying `process` to each node.

```c
void	append(sll_headnode_t *list, char *payload);
```
appends a new node to the list.

```c
sll_headnode_t	new_list(void);
```
list constructor, here for your own safety, returns an sll_t with only the head node.

```c
void	free_sll(sll_headnode_t *list);
```
frees the entire list.
