/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:36:14 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/28 17:53:56 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	main_core_rooter(t_pushswap *ps, int elements)
{
	if (is_already_sorted(ps))
		return ;
	if (elements == 1)
		return ;
	else if (elements == 2)
		elements_are_two(ps);
	else if (elements == 3)
		elements_are_three(ps);
	else if (elements == 4)
		elements_are_four(ps);
	else if (elements == 5)
		elements_are_five(ps);
	else
	{
		if (ranking_nodes(ps) != SUCCESS)
			end_program(EXIT_FAILURE, ps);
		radix_lsd(ps);
	}
}

static void	validate_and_load_args(t_pushswap *ps, char **ptrr)
{
	int			i;
	long long	num;

	i = 0;
	while (ptrr[i])
	{
		if (is_integer(ptrr[i]) == false)
		{
			end_program(EXIT_FAILURE, ps);
		}
		num = ft_atoll(ptrr[i]);
		if (is_value_duplicated(ps, num) != SUCCESS)
		{
			end_program(EXIT_FAILURE, ps);
		}
		if (add_to_tail(&ps->stack_a, num) != SUCCESS)
		{
			end_program(EXIT_FAILURE, ps);
		}
		i++;
	}
}

int	pushswap(char **ptrr, int elements)
{
	t_pushswap	ps;

	ps.stack_a = (t_stack){NULL, NULL};
	ps.stack_b = (t_stack){NULL, NULL};
	validate_and_load_args(&ps, ptrr);
	main_core_rooter (&ps, elements);
	free_stack (&ps.stack_a);
	return (0);
}

int	main(int arc, char **arv)
{
	char	**ptrr;

	if (arc < 2)
		return (EXIT_FAILURE);
	else if (arc == 2)
	{
		ptrr = split_spht(arv[1]);
		if (!ptrr)
			return (EXIT_FAILURE);
		else
		{
			pushswap(ptrr, ft_ptrrlen(ptrr));
			free_ptrr(ptrr);
		}
	}
	else
	{
		ptrr = &arv[1];
		pushswap(ptrr, arc - 1);
	}
	return (EXIT_SUCCESS);
}

// #include <stdio.h>
// void	debug_print_stack_a(t_pushswap *ps)
// {
// 	struct t_node	*c = ps->stack_a.head;

// 	c = ps->stack_a.head;
// 	while (c != NULL)
// 	{
// 		printf("%lld ",c->number);
// 		c = c->next;
// 	}
// 	printf("\n");
// }
