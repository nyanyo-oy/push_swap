#include "push_swap.h"

int do_sa(PushSwap *ps)
{
	return (swap(&ps->stack_a));
}

int sa(PushSwap *ps)
{
	if (do_sa(ps))
		return (-1);
	
	print_newline(ps);
	write(1, "sa", 2);
	return (0);
}

int	do_sb(PushSwap *ps)
{
	return (swap(&ps->stack_b));
}

int sb(PushSwap *ps)
{
	if (do_sb(ps))
		return (-1);
	
	print_newline(ps);
	write(1, "sb", 2);
	return (0);
}

int ss(PushSwap *ps)
{
	if (do_sa(ps) || do_sb(ps))
		return (-1);
	
	print_newline(ps);
	write(1, "ss", 2);
	return (0);
}






