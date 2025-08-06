#include "push_swap.h"
#include <string.h>

typedef struct Node
{
	int	number;
	struct	Node *next;
	struct	Node *prev;
} Node;

typedef struct Stack
{
	Node	*head;
	Node	*tail;
} Stack;

Stack stack_a = {NULL, NULL};
Stack stack_b = {NULL, NULL};

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
	}
	else
		stack->tail->next = current;
	stack->tail = current;

	return (0);
}

int	stack_head_to_head(Stack *dst, Stack *src)
{
	if (!src)
		return (-1);

	struct Node *new;
	new = (struct Node  *)malloc(sizeof(struct Node));
	if (!new)
		return (-1);
	new->number = src->head->number;
	src->head = src->head->next;
	if (src->head->next == NULL)
		src->tail = src->head;

	new->next = dst->head;
	dst->head = new;
	if (dst->head->next == NULL)
		dst->tail = dst->head->next;
	dst->head = new;
	return (0);
}

int move_tail_to_head(Stack *stack)
{

	stack->tail = NULL;
}

int	swap (Stack *stack)
{
	int tmp;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);

	tmp = stack->head->number;
	stack->head->number = stack->head->next->number;
	stack->head->next->number = tmp;

	return (0);
}

int sa(void)
{
	return (swap(&stack_a));
}

int sb(void)
{
	return (swap(&stack_b));
}

int ss(void)
{
	if (sa() == 0 && sb() == 0)
		return (0);
	return (-1);
}

int	pa(void)
{
	return (stack_head_to_head(&stack_a, &stack_b));
}

int	pb(void)
{
	return (stack_head_to_head(&stack_b, &stack_a));
}


void stack_arv(char **arv)
{
	int	i;
	Node *current;

	i = 0;
	while (arv[i])
	{
		current->number = ft_atoi(arv[i++]);
		current = current->next;
	}
}

#include <stdio.h>
#include <stdlib.h>
int	main (int arc, char **arv)
{
	int i;
	Node *current;

	if (arc == 4)
	{
		stack_arv(arv);
	}
	current = stack_a.head;
	while (current != stack_a.tail)
	{
		printf("%d ", current->number);
		current = current->next;
	}
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
