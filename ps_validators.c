/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:46:40 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/09 20:46:55 by kenakamu         ###   ########.fr       */
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
	return (parse_and_check_overflow(nptr, i, sign));
}
