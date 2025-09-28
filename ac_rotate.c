/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:10 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/10 17:00:31 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_pushswap *ps)
{
	if (move_head_to_tail(&ps->stack_a) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
}

void	ra(t_pushswap *ps)
{
	do_ra(ps);
	write(1, "ra\n", 3);
}

void	do_rb(t_pushswap *ps)
{
	if (move_head_to_tail(&ps->stack_b) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
}

void	rb(t_pushswap *ps)
{
	do_rb(ps);
	write(1, "rb\n", 3);
}

void	rr(t_pushswap *ps)
{
	if (move_head_to_tail(&ps->stack_a) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
	if (move_head_to_tail(&ps->stack_b) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
	write(1, "rr\n", 3);
}
