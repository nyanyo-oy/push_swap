/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:12 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/10 17:00:27 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_pushswap *ps)
{
	if (move_tail_to_head(&ps->stack_a) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
}

void	rra(t_pushswap *ps)
{
	do_rra(ps);
	write(1, "rra\n", 4);
}

void	do_rrb(t_pushswap *ps)
{
	if (move_tail_to_head(&ps->stack_b) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
}

void	rrb(t_pushswap *ps)
{
	do_rrb(ps);
	write(1, "rrb\n", 4);
}

void	rrr(t_pushswap *ps)
{
	if (move_tail_to_head(&ps->stack_a) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
	if (move_tail_to_head(&ps->stack_b) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
	write(1, "rrr\n", 4);
}
