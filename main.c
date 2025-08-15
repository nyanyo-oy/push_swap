/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:36:14 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/15 16:29:43 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft-42/libft.h"
#include "push_swap.h"
#include <string.h>

#include <stdio.h>
void	debug_print_stack_a(t_PushSwap *ps)
{
	struct Node	*c = ps->stack_a.head;

	write(1, "\n", 1);
	while (c != NULL)
	{
		printf("%d ",c->number);
		c = c->next;
	}
	printf("\n");
}

int	add_to_tail(t_Stack *stack, int num)
{
	struct Node	*current;

	current = (struct Node *)malloc(sizeof(struct Node));
	if (!current)
		return (-1);
	current->number = num;
	current->next = NULL;
	if (stack->tail == NULL)
	{
		stack->head = current;
		current->prev = NULL;
	}
	else
	{
		stack->tail->next = current;
		current->prev = stack->tail;
	}
	stack->tail = current;
	return (0);
}//safetyなし

int	stack_head_to_head(t_Stack *dst, t_Stack *src)//push
{
	struct Node	*new;
	struct Node	*old_node;

	if (!src || !src->head)
		return (-1);
	new = (struct Node *)malloc(sizeof(struct Node));
	if (!new)
		return (-1);
	new->number = src->head->number;
	old_node = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	free(old_node);
	new->next = dst->head;
	new->prev = NULL;
	if (dst->head)
		dst->head->prev = new;
	else
		dst->tail = new;
	dst->head = new;
	return (0);
}//safety要確認

int	move_head_to_tail(t_Stack *stack)//rotate
{
	struct Node	*tmp;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	tmp->prev = stack->tail;
	stack->tail->next = tmp;
	tmp->next = NULL;
	stack->tail = tmp;
	return (0);
}

int	move_tail_to_head(t_Stack *stack)//reverse_rotate
{
	struct Node	*tmp;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	tmp->next = stack->head;
	stack->head->prev = tmp;
	tmp->prev = NULL;
	stack->head = tmp;
	return (0);
}

int	swap(t_Stack *stack)
{
	int	tmp;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	tmp = stack->head->number;
	stack->head->number = stack->head->next->number;
	stack->head->next->number = tmp;
	return (0);
}//safety要確認

int	count_elements(t_PushSwap *ps)
{
	struct Node	*tmp;
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

void	radix_lsd_core(t_PushSwap *ps, int range)
{
	int	elements;
	int	bit_counts;
	int	n;
	int	shifts;

	elements = count_elements(ps);
	bit_counts = 0;
	while (bit_counts < 63 && (1 << bit_counts) <= range)
		bit_counts++;
	shifts = 0;
	while (bit_counts--)//ここほんとうにあってる？？
	{
		n = elements;
		while (n--)
		{
			if ((ps->stack_a.head->number >> shifts) & 1)
				ra(ps);
			else
				pb(ps);
		}
		while (ps->stack_b.head != NULL)
			pa(ps);
		shifts++;
	}
}

void	radix_lsd(t_PushSwap *ps)
{
	int	min;
	int	max;
	int	range;

	min = search_min(ps);
	max = search_max(ps);
	range = max - min;


	// nomalize(ps, min);
	radix_lsd_core(ps, range);
	// de_nomalize(ps, min);
}

bool	is_already_sorted(t_PushSwap *ps)
{
	struct Node	*tmp;

	if (ps->stack_a.head == ps->stack_a.tail)
		return (true);

	tmp = ps->stack_a.head->next;
	while (tmp != NULL && tmp->prev->number < tmp->number)
		tmp = tmp->next;

	return (tmp == NULL);
}

bool	has_duplicate(t_PushSwap *ps, int num)
{
	struct Node* target;

	if (!ps->stack_a.head)
		return (false);

	target = ps->stack_a.head;
	while(target != NULL)
	{
		if (target->number == num)
			return (true);
		target = target->next;
	}
	return (false);
}

void	main_core(char **ptrr)
{
	t_PushSwap	ps;
	int			i;
	int	num;

	ps.stack_a = (t_Stack){NULL, NULL};
	ps.stack_b = (t_Stack){NULL, NULL};
	i = 0;
	while (ptrr[i])
	{
		if (!is_int_num(ptrr[i]))
		{
			write(STDOUT_FILENO, "Error\n", 6);
			exit(1);
		}
		num = ft_atoi(ptrr[i]);
		if (has_duplicate(&ps, num))
		{
			write(STDOUT_FILENO, "Error\n", 6);
			exit(1);
		}
		add_to_tail(&ps.stack_a, num);
		i++;
	}

	if (is_already_sorted(&ps))
		return ;

	if (i == 1)
		elements_are_one(&ps);
	else if (i == 2)
		elements_are_two(&ps);
	else if (i == 3)
		elements_are_three(&ps);
	else if (i == 4)
		elements_are_four(&ps);
	else if (i == 5)
		elements_are_five(&ps);
	else
		radix_lsd(&ps);
	// debug_print_stack_a(&ps);
}


#include <stdlib.h>
int	main (int arc, char **arv)
{
	char	**ptrr;

	if (arc == 2)
	{
		ptrr = split_spht(arv[1]);
		main_core(ptrr);
	}
	else if (arc >= 3)
	{
		ptrr = &arv[1];
		main_core(ptrr);
	}
	return (0);
}
