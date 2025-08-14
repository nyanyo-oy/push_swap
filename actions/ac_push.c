/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:17 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/14 12:13:18 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_newline(t_PushSwap *ps)
// {
// 	if (ps->operation_count > 0)
// 		write(1, "\n", 1);
// 	ps->operation_count++;
// }

int	pa(t_PushSwap *ps)
{
	if (stack_head_to_head(&ps->stack_a, &ps->stack_b))
		return (-1);
	// print_newline(ps);
	write (1, "pa\n", 3);
	return (0);
}

int	pb(t_PushSwap *ps)
{
	if (stack_head_to_head(&ps->stack_b, &ps->stack_a))
		return (-1);
	// print_newline(ps);
	write(1, "pb\n", 3);
	return (0);
}