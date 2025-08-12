#include "push_swap.h"

int do_rra(PushSwap *ps)
{
	return (move_tail_to_head(&ps->stack_a));
}

int rra(PushSwap *ps)
{	
	if (do_rra(ps))
		return (-1);
	
	print_newline(ps);
	write(1, "rra", 3);
	return (0);
}

int do_rrb(PushSwap *ps)
{
	return (move_tail_to_head(&ps->stack_b));
}

int rrb(PushSwap *ps)
{
	if (do_rrb(ps))
		return (-1);
	
	print_newline(ps);
	write(1, "rrb", 3);
	return (0);
}

int rrr(PushSwap *ps)
{
	if (rra(ps) || rrb(ps))
		return (-1);
	
	print_newline(ps);
	write(1, "rra", 1);
	return (0);
}