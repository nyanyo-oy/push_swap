#include "push_swap.h"

int	pa(PushSwap *ps)
{
	if (stack_head_to_head(&ps->stack_a, &ps->stack_b))
		return (-1);
	
	print_newline(ps);
	write (1, "pa", 2);
	return (0);
}

int	pb(PushSwap *ps)
{
	if (stack_head_to_head(&ps->stack_b, &ps->stack_a))
		return (-1);
	
	print_newline(ps);
	write(1, "pb", 2);
	return (0);
}