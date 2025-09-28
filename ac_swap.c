/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:07 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/10 17:00:36 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_pushswap *ps)
{
	if (swap(&ps->stack_a) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
}

void	sa(t_pushswap *ps)
{
	do_sa(ps);
	write(1, "sa\n", 3);
}

void	do_sb(t_pushswap *ps)
{
	if (swap(&ps->stack_b) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
}

void	sb(t_pushswap *ps)
{
	do_sb(ps);
	write(1, "sb\n", 3);
}

void	ss(t_pushswap *ps)
{
	if (swap(&ps->stack_a) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
	if (swap(&ps->stack_b) != SUCCESS)
		end_program(EXIT_FAILURE, ps);
	write(1, "ss\n", 3);
}
