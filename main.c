/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:36:14 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/14 20:40:26 by kenakamu         ###   ########.fr       */
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
		ranking_nodes(ps);
		radix_lsd(ps);
	}
}

static int	validate_and_load_args(t_pushswap *ps, char **ptrr)
{
	int			i;
	long long	num;

	i = 0;
	while (ptrr[i])
	{
		if (is_integer(ptrr[i]) == false)
		{
			free_stack (&ps->stack_a);
			return (1);
		}
		num = ft_atoll(ptrr[i]);
		if (is_value_duplicated(ps, num) != SUCCESS)
		{
			free_stack (&ps->stack_a);
			return (1);
		}
		if (add_to_tail(&ps->stack_a, num) != SUCCESS)
		{
			free_stack (&ps->stack_a);
			return (1);
		}
		i++;
	}
	return (0);
}

int	pushswap(char **ptrr, int elements)
{
	t_pushswap	ps;

	ps.stack_a = (t_stack){NULL, NULL};
	ps.stack_b = (t_stack){NULL, NULL};
	if (validate_and_load_args(&ps, ptrr) != SUCCESS)
		return (1);
	main_core_rooter (&ps, elements);
	free_stack (&ps.stack_a);
	return (0);
}

int	main(int arc, char **arv)
{
	char	**ptrr;
	int		ret;

	ret = 0;
	if (arc < 2)
		return (0);
	else if (arc == 2)
	{
		ptrr = split_spht(arv[1]);
		if (!ptrr)
			ret = 1;
		else
		{
			ret = pushswap(ptrr, ft_ptrrlen(ptrr));
			free_ptrr(ptrr);
		}
	}
	else
	{
		ptrr = &arv[1];
		ret = pushswap(ptrr, arc - 1);
	}
	if (ret == 1)
		write(STDOUT_FILENO, "Error\n", 6);
	return (ret);
}

// #include <stdio.h>
// void	debug_print_stack_a(t_pushswap *ps)
// {
// 	struct t_node	*c = ps->stack_a.head;

// 	while (c != NULL)
// 	{
// 		printf("%lld ",c->rank);
// 		c = c->next;
// 	}
// 	printf("\n");
// 	c = ps->stack_a.head;
// 	while (c != NULL)
// 	{
// 		printf("%lld ",c->number);
// 		c = c->next;
// 	}
// 	printf("\n");
// }
