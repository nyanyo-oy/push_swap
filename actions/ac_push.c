/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:13:17 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 13:37:34 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pushswap *ps)
{
	stack_head_to_head(&ps->stack_a, &ps->stack_b);
	write (1, "pa\n", 3);
}

void	pb(t_pushswap *ps)
{
	stack_head_to_head(&ps->stack_b, &ps->stack_a);
	write(1, "pb\n", 3);
}
