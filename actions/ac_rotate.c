#include "push_swap.h"

int do_ra(PushSwap *ps)
{
	return (move_head_to_tail(&ps->stack_a));
}

int ra(PushSwap *ps)
{
	if (do_ra(ps))
		return (-1);
	
	print_newline(ps);
	write(1, "ra", 2);
	return (0);
}

int do_rb(PushSwap *ps)
{
	return (move_head_to_tail(&ps->stack_b));
}

int rb(PushSwap *ps)
{
	if (do_rb(ps))
		return (-1);
	
	print_newline(ps);
	write(1, "rb", 2);
	return (0);
}

int rr(PushSwap *ps)
{
	if (do_ra(ps) || do_rb(ps))
		return (-1);
	
	print_newline(ps);
	write(1, "rr", 2);
	return (0);
}