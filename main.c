#include "libft-42/libft.h"
#include "push_swap.h"
#include <string.h>

#include <stdio.h>
void	debug_print_stack_a(PushSwap *ps)		
{
	struct Node *c = ps->stack_a.head;
	
	write(1, "\n", 1);
	while (c != NULL)
	{
		printf("%d ",c->number);
		c = c->next;
	}
	printf("\n");
}

// int	add_to_head (Stack *stack, int num)//stillbeta
// {
// 	struct Node *current;
// 	current = (struct Node *)malloc(sizeof(struct Node));
// 	if (!current)
// 		return (-1);

// 	current->number = num;
// 	current->prev = NULL;
// 	if (stack->head == NULL)
// 	{
// 		stack->tail = current;
// 		current->next = NULL;
// 	}
// 	else
// 	{
// 		stack->head->prev = current;
// 		current->next = stack->head;
// 	}
// 	stack->head = current;

// 	return (0);
// }//safetyなし

int	add_to_tail (Stack *stack, int num)
{
	struct Node *current;
	current = (struct Node *)malloc(sizeof(struct Node));
	if (!current)
		return (-1);

	current->number = num;
	current->next = NULL;
	if (stack->tail == NULL)
	{
		stack->head = current;
		current->prev = NULL;
	}
	else
	{
		stack->tail->next = current;
		current->prev = stack->tail;
	}
	stack->tail = current;

	return (0);
}//safetyなし


bool	is_stack_empty(Stack *stack)
{
	return (!stack || !stack->head);//stackが空の場合、headがNULLの場合
}

int	stack_head_to_head(Stack *dst, Stack *src)//push
{
	if (is_stack_empty(src))
		return (-1);

	struct Node *new;
	struct Node	*old_node;
	new = (struct Node *)malloc(sizeof(struct Node));
	if (!new)
		return(-1);
	
	new->number = src->head->number;

	old_node = src->head;
	src->head = src->head->next;
	
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;//stuckが空
	
	free(old_node);
	
	new->next = dst->head;
	new->prev = NULL;
	
	if (dst->head)
		dst->head->prev = new;
	else
		dst->tail = new;
	
	dst->head = new;

	return (0);
}//safety要確認


int move_head_to_tail(Stack *stack)//rotate
{
	if (!stack)
		return (-1);

	struct Node	*tmp;

	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next->prev = NULL;

	tmp->prev = stack->tail;
	stack->tail->next = tmp;
	tmp->next = NULL;

	stack->tail = tmp;

	return (0);
}//stack内要素一つのみのsafety未実装

int move_tail_to_head(Stack *stack)//reverse_rotate
{
	if (!stack)
		return (-1);

	struct Node	*tmp;

	tmp = stack->tail;
	stack->tail = tmp->prev;
	tmp->prev->next = NULL;

	tmp->next = stack->head;
	stack->head->prev = tmp;
	tmp->prev = NULL;

	stack->head = tmp;

	return (0);
}//stack内要素stackなしまたは一つのみのsafety未実装

int	swap (Stack *stack)
{
	int tmp;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);

	tmp = stack->head->number;
	stack->head->number = stack->head->next->number;
	stack->head->next->number = tmp;

	return (0);
}//safety要確認

void radix_lsd(PushSwap *ps, int elements)
{
	int	min;
	int max;
	int	range;
	int	shifts;
	int	remaining;
	int	bit_counts;
	
	min = search_min(ps);
	max = search_max(ps);
	range = max - min;
	
	nomalize(ps, min);
	
	bit_counts = 0;
	while ((1 << bit_counts) <= range)
		bit_counts++;
	printf("max=%d, min=%d, max_value=%d, bit_counts=%d\n", 
       max, min, max - min, bit_counts);
	
	shifts = 0;
	while (bit_counts--)//桁数
	{
		remaining = elements;
		while (remaining--)//要素数
		{
			if ((ps->stack_a.head->number >> shifts ) & 1)
				ra(ps);
			else 
				pb(ps);
		}
		while (ps->stack_b.head != NULL)
		{
			pa(ps);
		}
		shifts++;
	}

	de_nomalize(ps, min);
}

// int	set_reverse(PushSwap *ps, int elements)
// {
// 	while(elements--)
// 	{
// 		if (!ra(ps))
// 			return (-1);
// 	}
// 	return (0);
// }
void	main_core(char **ptrr)
{
	PushSwap	ps;
	ps.stack_a = (Stack){NULL, NULL};
	ps.stack_b = (Stack){NULL, NULL};
	ps.operation_count = 0;
	int	i;
	
	i = 0;
	while(ptrr[i])
	{
		add_to_tail(&ps.stack_a, ft_atoi(ptrr[i]));
		i++;
	}
	// printf ("\n%d\n", i);
	radix_lsd(&ps, i);
	// debug_print_stack_a(&ps);
	// set_reverse(&ps, i);
	debug_print_stack_a(&ps);
}

#include <stdlib.h>
int	main (int arc, char **arv)
{

	char		**ptrr;
	// int i;
	
	if (arc == 2)
	{
		ptrr = split_spht(arv[1]);
		// i = 0;
		// while(ptrr[i])
		// {
		// 	add_to_tail(&ps.stack_a, ft_atoi(ptrr[i]));
		// 	i++;
		// }
		// i = 0;
		// while (ptrr[i++])
		// radix_lsd(&ps, i);
		// debug_print_stack_a(&ps);
		main_core(ptrr);
	}
	if (arc >= 3)
	{
		ptrr = &arv[1];
		// i = 1;
		// while (arv[i])
		// {
		// 	add_to_tail(&ps.stack_a, ft_atoi(arv[i]));
		// 	i++;
		// }
		// radix_lsd(&ps, arc - 1);
		// debug_print_stack_a(&ps);
		main_core(ptrr);
	}
	write (1, "\n", 1);
	
	return (0);
}


