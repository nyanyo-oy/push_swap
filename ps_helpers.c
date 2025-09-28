/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:59:56 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/12 15:20:59 by kenakamu         ###   ########.fr       */
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

void	free_stack(t_stack *stack)
{
	struct t_node	*target;

	if (!stack)
		return ;
	while (stack->head != NULL)
	{
		target = stack->head;
		stack->head = stack->head->next;
		free (target);
	}
	stack->head = NULL;
	stack->tail = NULL;
}

void	end_program(int exit_status, t_pushswap *ps)
{
	free_stack(&ps->stack_a);
	free_stack(&ps->stack_b);
	if (exit_status == EXIT_FAILURE)
		write(STDOUT_FILENO, "Error\n", 6);
	exit(exit_status);
}
