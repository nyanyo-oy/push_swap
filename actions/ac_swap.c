/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:07 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/14 12:13:08 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_sa(t_PushSwap *ps)
{
	return (swap(&ps->stack_a));
}

int	sa(t_PushSwap *ps)
{
	if (do_sa(ps))
		return (-1);
	print_newline(ps);
	write(1, "sa", 2);
	return (0);
}

int	do_sb(t_PushSwap *ps)
{
	return (swap(&ps->stack_b));
}

int	sb(t_PushSwap *ps)
{
	if (do_sb(ps))
		return (-1);
	print_newline(ps);
	write(1, "sb", 2);
	return (0);
}

int	ss(t_PushSwap *ps)
{
	if (do_sa(ps) || do_sb(ps))
		return (-1);
	print_newline(ps);
	write(1, "ss", 2);
	return (0);
}
