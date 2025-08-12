#include "libft-42/libft.h"
#include "push_swap.h"
#include <string.h>

// Node *add_between (Node *prev, int num, Node *next)
// {
// 	struct Node *current;
// 	current = (struct Node *)malloc(sizeof(struct Node));
// 	if (!current)
// 		return (NULL);

// 	current->number = num;
// 	if (prev)
// 		prev->next = current;
// 	current->next = next;

// 	if (!prev && !head)
// 		head = current;
// 	if (!next)
// 		tail = current;

// 	return (current);
// }


int	add_to_tail (Stack *stack, int num)
{
	struct Node *current;
	current = (struct Node *)malloc(sizeof(struct Node));
	if (!current)
		return (-1);

	current->number = num;
	current->next = NULL;
	if (stack->head == NULL)
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

int	stack_head_to_head(Stack *dst, Stack *src)//push
{
	if (!src)
		return (-1);

	struct Node *new;
	new = (struct Node  *)malloc(sizeof(struct Node));
	if (!new)
		return (-1);
		new->number = src->head->number;

	src->head = src->head->next;//nextがNULLの場合NULLにちゃんとなる
	src->head->prev = NULL;
	src->tail = src->head;//headがNULLになるとここもNULLになる

	new->next = dst->head;
	dst->head->prev = new;
	dst->head = new;
	new->prev = NULL;
	if (dst->head->next == NULL)
		dst->tail = new;

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

void push_swap(PushSwap *ps, int elements)
{
	int	min;
	int max;
	int	range;
	int	i;
	int	shifts;
	
	min = search_min(ps);
	max = search_max(ps);
	range = max - min;
	
	nomalize(ps, min);
	
	shifts = 0;
	while (range--)//桁数
	{
		i = 0;
		while (elements - i)//要素数
		{
			if ((ps->stack_a.head->number >> shifts ) & 1)
			{
				ra(ps);
				pb(ps);
			}
			else 
				ra(ps);
			i++;
		}
		while (ps->stack_b.head != NULL)
		{
			pa(ps);
			ra(ps);
		}
		shifts++;
	}
	de_nomalize(ps, min);
}


#include <stdio.h>
#include <stdlib.h>
int	main (int arc, char **arv)
{
	PushSwap	ps;
	ps.stack_a = (Stack){NULL, NULL};
	ps.stack_b = (Stack){NULL, NULL};
	ps.operation_count = 0;
	
	int i;
	
	if (arc >= 2)
	{
		i = 0;
		while (arv[i])
		{
			add_to_tail(&ps.stack_a, ft_atoi(arv[i]));
			i++;
		}
		push_swap(&ps, arc - 1);
	}
	write (1, "Error", 5);
	
	return (0);
}



//while (current != NULL)
//	{
//		if (current->num > current->num)
//			break;
//		prev = current;
//		current = current->next;
//	}
//
//	prev->next = current;
//	current->next = current;
