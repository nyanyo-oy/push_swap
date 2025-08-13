#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft-42/libft.h"

typedef struct	Node
{
	int	number;
	struct Node	*next;
	struct Node	*prev;
} Node;

typedef struct	Stack
{
	Node	*head;
	Node	*tail;
} Stack;

typedef struct	PushSwap
{
	Stack	stack_a;
	Stack	stack_b;
	int		operation_count;
} PushSwap;

int	add_to_tail (Stack *stack, int num);

int	stack_head_to_head(Stack *dst, Stack *src);//push
int move_tail_to_head(Stack *stack);//reverse_rotate
int move_head_to_tail(Stack *stack);//rotate
int	swap (Stack *stack);


int sa(PushSwap *ps);
int sb(PushSwap *ps);
int ss(PushSwap *ps);

int	pa(PushSwap *ps);
int	pb(PushSwap *ps);

int ra(PushSwap *ps);
int rb(PushSwap *ps);
int rr(PushSwap *ps);

int rra(PushSwap *ps);
int rrb(PushSwap *ps);
int rrr(PushSwap *ps);


int	search_min(PushSwap *ps);
int	search_max(PushSwap *ps);

void	nomalize(PushSwap *ps, int min);
void	de_nomalize(PushSwap *ps, int min);

void	print_newline(PushSwap *ps);

void radix_lsd(PushSwap *ps, int elements);



// PushSwap *ps stack_arv(char **arv);