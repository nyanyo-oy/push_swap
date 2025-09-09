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

static int	search_min_index(t_pushswap *ps)
{
	struct t_node *tmp;
	int	min;
	int	i;
	
	tmp = ps->stack_a.head->next;
	min = ps->stack_a.head->number;
	while (tmp != NULL)
	{
		if (min > tmp->number)
			min = tmp->number;
		tmp = tmp->next;
	}
	
	tmp = ps->stack_a.head;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->number == min)
			break;
		tmp = tmp->next;
		i++;
	}
	return (i);
}
void	elements_are_two(t_pushswap *ps)
{
	if (ps->stack_a.head->number > ps->stack_a.tail->number)
		ra(ps);
}

void	elements_are_three(t_pushswap *ps)
{
	if (ps->stack_a.head->number > ps->stack_a.head->next->number && 
		ps->stack_a.head->number > ps->stack_a.tail->number)
	{
		ra(ps);
	}
	else if (ps->stack_a.head->next->number > ps->stack_a.head->number && 
		ps->stack_a.head->next->number > ps->stack_a.tail->number)
	{
		rra(ps);
	}
	
	if (ps->stack_a.head->number > ps->stack_a.head->next->number)
	{
		sa(ps);
	}
}

void	elements_are_four(t_pushswap *ps)
{
	int	i;

	i = search_min_index(ps);
	if (i == 1)
	{
		sa(ps);
	}
	else if (i == 2)
	{
		rra(ps);
		rra(ps);
	}
	else if (i == 3)
	{
		rra(ps);
	}
	pb(ps);
	elements_are_three(ps);
	pa(ps);
}

void	elements_are_five(t_pushswap *ps)
{
	int i;
	i = search_min_index(ps);
	if (i == 1)
		sa(ps);
	else if (i == 2)
	{
		ra(ps);
		ra(ps);
	}
	else if (i == 3)
	{
		rra(ps);
		rra(ps);
	}
	else if (i == 4)
		rra(ps);
	pb(ps);	
	elements_are_four(ps);
	pa(ps);
}
