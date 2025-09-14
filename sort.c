/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:07:16 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/12 15:28:44 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_lsd_alg(t_pushswap *ps, int bit_counts, int elements)
{
	int	n;
	int	shifts;

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

void	radix_lsd(t_pushswap *ps)
{
	int			elements;
	long long	bit_counts;

	elements = count_elements(ps);
	bit_counts = 0;
	while (bit_counts < 63 && (1LL << bit_counts) <= elements - 1)
		bit_counts++;
	radix_lsd_alg(ps, bit_counts, elements);
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

static void	ranking_nodes_relay_ranks(t_pushswap *ps,
				long long *rank, int elements)
{
	struct t_node	*tmp;
	int				k;

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
}

int	ranking_nodes(t_pushswap *ps)
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
	ranking_nodes_relay_ranks(ps, rank, elements);
	free (rank);
	return (0);
}
