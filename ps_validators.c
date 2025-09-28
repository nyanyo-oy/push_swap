/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:46:40 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/28 20:39:05 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static bool	parse_and_check_overflow(const char *nptr, int start, int sign)
{
	long	result;
	int		i;
	bool	has_digit;

	result = 0;
	i = start;
	has_digit = false;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		has_digit = true;
		result = (result * 10) + (nptr[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return (false);
		if (sign == -1 && result > (long)INT_MAX + 1)
			return (false);
		i++;
	}
	if (nptr[i] != '\0' || !has_digit)
		return (false);
	return (true);
}

bool	is_integer(const char *nptr)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	return (parse_and_check_overflow(nptr, i, sign));
}

bool	is_value_duplicated(t_pushswap *ps, long long num)
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
