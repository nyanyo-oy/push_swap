/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:10 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 13:41:18 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_PushSwap *ps)
{
	move_head_to_tail(&ps->stack_a);
}

void	ra(t_PushSwap *ps)
{
	do_ra(ps);
	write(1, "ra\n", 3);
}

void	do_rb(t_PushSwap *ps)
{
	move_head_to_tail(&ps->stack_b);
}

void	rb(t_PushSwap *ps)
{
	do_rb(ps);
	write(1, "rb\n", 3);
}

void	rr(t_PushSwap *ps)
{
	do_ra(ps);
	do_rb(ps);
	write(1, "rr\n", 3);
}
