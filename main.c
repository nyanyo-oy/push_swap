/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:36:14 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 14:56:19 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft-42/libft.h"
#include "push_swap.h"
#include <string.h>

#include <stdio.h>





long long	count_elements(t_PushSwap *ps)
{
	struct t_node	*tmp;
	int			elements;

	tmp = ps->stack_a.head;
	elements = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		elements++;
	}
	return (elements);
}

void	radix_lsd(t_PushSwap *ps)
{
	int			elements;
	long long	bit_counts;
	int			n;
	int			shifts;
	long long	range;

	elements = count_elements(ps);
	range = elements - 1;
	bit_counts = 0;
	while (bit_counts < 63 && (1LL << bit_counts) <= range)
		bit_counts++;
	shifts = 0;
	while (bit_counts--)
	{
		n = elements;
		while (n--)
		{
			if ((ps->stack_a.head->rank >> shifts) & 1)
				ra(ps);
			else
				pb(ps);
		}
		while (ps->stack_b.head != NULL)
			pa(ps);
		shifts++;
	}
}

long long	*bubble(long long *rank, int elements)
{
	long long	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < elements - 1)
	{
		j = 0;
		while (j < elements - 1 - i)
		{
			if (rank[j] > rank[j + 1])
			{
				tmp = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (rank);
}

int	raning_nodes(t_PushSwap *ps)
{
	struct t_node	*tmp;
	long long		*rank;
	int				k;
	int				elements;

	elements = count_elements(ps);
	rank = (long long *)malloc(sizeof(long long) * elements);
	if (!rank)
		return (-1);
	tmp = ps->stack_a.head;
	k = 0;
	while (tmp != NULL)
	{
		rank[k++] = tmp->number;
		tmp = tmp->next;
	}
	rank = bubble(rank, elements);
	k = 0;
	tmp = ps->stack_a.head;
	while (tmp != NULL)
	{
		k = 0;
		while (k < elements)
		{
			if (tmp->number == rank[k])
			{
				tmp->rank = k;
				break ;
			}
			k++;
		}
		tmp = tmp->next;
	}
	free (rank);
	return (0);
}

int	main_core(char **ptrr)
{
	t_PushSwap	ps;
	int			i;
	long long	num;

	ps.stack_a = (t_Stack){NULL, NULL};
	ps.stack_b = (t_Stack){NULL, NULL};

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
	if (is_already_sorted(&ps))
		return (0);

	if (i == 1)
		return (0);
	else if (i == 2)
		elements_are_two(&ps);
	else if (i == 3)
		elements_are_three(&ps);
	else if (i == 4)
		elements_are_four(&ps);
	else if (i == 5)
		elements_are_five(&ps);
	else
	{
		raning_nodes(&ps);
		radix_lsd(&ps);
	}
	return (0);
}

int	main (int arc, char **arv)
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

//void	debug_print_stack_a(t_PushSwap *ps)
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