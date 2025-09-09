/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:12 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 13:39:24 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_pushswap *ps)
{
	move_tail_to_head(&ps->stack_a);
}

void	rra(t_pushswap *ps)
{
	do_rra(ps);
	write(1, "rra\n", 4);
}

void	do_rrb(t_pushswap *ps)
{
	move_tail_to_head(&ps->stack_b);
}

void	rrb(t_pushswap *ps)
{
	do_rrb(ps);
	write(1, "rrb\n", 4);
}

void	rrr(t_pushswap *ps)
{
	rra(ps);
	rrb(ps);
	write(1, "rrr\n", 4);
}
