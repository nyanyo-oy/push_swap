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
	return (0);
}

int search_min_index(t_PushSwap *ps)
{
	struct Node *tmp;
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

int	elements_are_four(t_PushSwap *ps)
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
	return (0);
}

void elements_are_five_core(t_PushSwap *ps)
{
	int i;
	i = search_min_index(ps);
	if (i == 1)
	{
		sa(ps);
	}
	if (i == 2)
	{
		ra(ps);
		ra(ps);
	}
	if (i == 3)
	{
		rra(ps);
		rra(ps);
	}
	else if (i == 4)
	{
		rra(ps);
	}
	pb(ps);

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
}

int	elements_are_five(t_PushSwap *ps)
{
	elements_are_five_core(ps);
	elements_are_three(ps);
	pa(ps);
	pa(ps);
	return (0);
}
