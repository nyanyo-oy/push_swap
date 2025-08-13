#include "push_swap.h"

int	search_min(PushSwap *ps)
{	
	struct Node	*target;
	int	min;
	
	target = ps->stack_a.head;
	if (ps->stack_a.head == ps->stack_a.tail)
		return(target->number);
	
	min = target->number;
	target = target->next;
	while (target != NULL)
	{
		if (min > target->number)
			min = target->number;
		target = target->next;
	}
	return (min);
}

int	search_max(PushSwap *ps)
{	
	struct Node	*target;
	int	max;
	
	target = ps->stack_a.head;
	if (ps->stack_a.head == ps->stack_a.tail)
		return(target->number);
	
	max = target->number;
	target = target->next;
	while (target != NULL)
	{
		if (max < target->number)
			max = target->number;
		target = target->next;
	}
	return (max);
}

void	nomalize(PushSwap *ps, int min)
{
	struct Node	*target;
	
	target = ps->stack_a.head;
	
	while (target != NULL)
	{
		target->number -= min;
		target = target->next;
	}
}

void	de_nomalize(PushSwap *ps, int min)
{
	struct Node	*target;
		
		target = ps->stack_a.head;
		
		while (target != NULL)
		{
			target->number += min;
			target = target->next;
		}
}

void	print_newline(PushSwap *ps)
{
	if (ps->operation_count > 0)
		write(1, "\n", 1);
	ps->operation_count++;
}