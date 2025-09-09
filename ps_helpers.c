/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:59:56 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 16:06:19 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	count_elements(t_pushswap *ps)
{
	struct t_node	*tmp;
	int				elements;

	tmp = ps->stack_a.head;
	elements = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		elements++;
	}
	return (elements);
}

bool	is_already_sorted(t_pushswap *ps)
{
	struct t_node	*tmp;

	if (ps->stack_a.head == ps->stack_a.tail)
		return (true);

	tmp = ps->stack_a.head->next;
	while (tmp != NULL && tmp->prev->number < tmp->number)
		tmp = tmp->next;

	return (tmp == NULL);
}

bool	has_duplicate(t_pushswap *ps, long long num)
{
	struct t_node	*target;

	if (!ps->stack_a.head)
		return (false);

	target = ps->stack_a.head;
	while (target != NULL)
	{
		if (target->number == num)
			return (true);
		target = target->next;
	}
	return (false);
}

bool	is_int_num(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return (false);
		if (sign == -1 && result > (long)INT_MAX + 1)
			return (false);
		i++;
	}
	if (nptr[i] != '\0')
		return (false);
	return (true);
}

long long	ft_atoll(const char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
