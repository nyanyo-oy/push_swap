/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:48:00 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/14 12:08:45 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	let_min_head(t_PushSwap *ps, int n)
{
	while (n--)
	{
		if (ps->stack_a.head->number < ps->stack_a.head->next->number)
			sa(ps);
		ra(ps);
	}
}

int	elements_are_one(t_PushSwap *ps)
{
	(void)ps;
	return (0);
}

int	elements_are_two(t_PushSwap *ps)
{
	if (ps->stack_a.head->number > ps->stack_a.tail->number)
		ra(ps);
	return (0);
}

int	elements_are_three(t_PushSwap *ps)
{
	let_min_head(ps, 3);
	if (ps->stack_a.head->next->number > ps->stack_a.tail->number)
	{
		sa(ps);
		ra(ps);
	}
	return (0);
}

int	elements_are_four(t_PushSwap *ps)
{
	let_min_head(ps, 4);
	pb(ps);
	elements_are_three(ps);
	pa(ps);
	return (0);
}

int	elements_are_five(t_PushSwap *ps)
{
	let_min_head(ps, 5);
	pb(ps);
	elements_are_four(ps);
	pa(ps);
	return (0);
}
