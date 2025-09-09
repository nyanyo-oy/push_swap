/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:36:14 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 16:48:05 by kenakamu         ###   ########.fr       */
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

static int	main_core(char **ptrr)
{
	t_pushswap	ps;
	int			i;
	long long	num;

	ps.stack_a = (t_stack){NULL, NULL};
	ps.stack_b = (t_stack){NULL, NULL};
	i = 0;
	while (ptrr[i])
	{
		if (!is_int_num(ptrr[i]))
		{
			write(STDOUT_FILENO, "Error\n", 6);
			return (-1);
		}
		num = ft_atoll(ptrr[i]);
		if (has_duplicate(&ps, num))
		{
			write(STDOUT_FILENO, "Error\n", 6);
			return (-1);
		}
		add_to_tail(&ps.stack_a, num);
		i++;
	}
	main_core_rooter (&ps, i);
	return (0);
}

int	main(int arc, char **arv)
{
	char	**ptrr;
	int		i;
	int		ret;

	ret = 0;
	if (arc < 2)
		return (0);
	if (arc == 2)
	{
		ptrr = split_spht(arv[1]);
		if (!ptrr)
			return (-1);
		ret = main_core(ptrr);
		i = 0;
		while (ptrr[i])
			free (ptrr[i++]);
		free(ptrr);
	}
	else
	{
		ptrr = &arv[1];
		ret = main_core(ptrr);
	}
	return (ret);
}

//void	debug_print_stack_a(t_pushswap *ps)
//{
//	struct t_node	*c = ps->stack_a.head;

//	while (c != NULL)
//	{
//		printf("%lld ",c->rank);
//		c = c->next;
//	}
//	printf("\n");
//	c = ps->stack_a.head;
//	while (c != NULL)
//	{
//		printf("%lld ",c->number);
//		c = c->next;
//	}
//	printf("\n");
//}
