/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:47:40 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/14 15:33:27 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_min(t_PushSwap *ps)
{
	struct Node	*target;
	int			min;

	target = ps->stack_a.head;
	if (ps->stack_a.head == ps->stack_a.tail)
		return (target->number);
	min = target->number;
	target = target->next;
	while (target != NULL)
	{
		if (min > target->number)
			min = target->number;
		target = target->next;
	}
	return (min);
}

int	search_max(t_PushSwap *ps)
{
	struct Node	*target;
	int			max;

	target = ps->stack_a.head;
	if (ps->stack_a.head == ps->stack_a.tail)
		return (target->number);
	max = target->number;
	target = target->next;
	while (target != NULL)
	{
		if (max < target->number)
			max = target->number;
		target = target->next;
	}
	return (max);
}

void	nomalize(t_PushSwap *ps, int min)
{
	struct Node	*target;

	target = ps->stack_a.head;
	while (target != NULL)
	{
		target->number -= min;
		target = target->next;
	}
}

void	de_nomalize(t_PushSwap *ps, int min)
{
	struct Node	*target;

	target = ps->stack_a.head;
	while (target != NULL)
	{

		target->number += min;
		target = target->next;
	}
}

