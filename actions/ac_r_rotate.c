/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:12 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/14 12:13:13 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_rra(t_PushSwap *ps)
{
	return (move_tail_to_head(&ps->stack_a));
}

int	rra(t_PushSwap *ps)
{
	if (do_rra(ps))
		return (-1);
	print_newline(ps);
	write(1, "rra", 3);
	return (0);
}

int	do_rrb(t_PushSwap *ps)
{
	return (move_tail_to_head(&ps->stack_b));
}

int	rrb(t_PushSwap *ps)
{
	if (do_rrb(ps))
		return (-1);
	print_newline(ps);
	write(1, "rrb", 3);
	return (0);
}

int	rrr(t_PushSwap *ps)
{
	if (rra(ps) || rrb(ps))
		return (-1);
	print_newline(ps);
	write(1, "rra", 1);
	return (0);
}