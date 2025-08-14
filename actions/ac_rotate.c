/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:10 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/14 12:13:11 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_ra(t_PushSwap *ps)
{
	return (move_head_to_tail(&ps->stack_a));
}

int	ra(t_PushSwap *ps)
{
	if (do_ra(ps))
		return (-1);
	print_newline(ps);
	write(1, "ra", 2);
	return (0);
}

int	do_rb(t_PushSwap *ps)
{
	return (move_head_to_tail(&ps->stack_b));
}

int	rb(t_PushSwap *ps)
{
	if (do_rb(ps))
		return (-1);
	print_newline(ps);
	write(1, "rb", 2);
	return (0);
}

int	rr(t_PushSwap *ps)
{
	if (do_ra(ps) || do_rb(ps))
		return (-1);
	print_newline(ps);
	write(1, "rr", 2);
	return (0);
}