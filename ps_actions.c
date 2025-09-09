/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:28:18 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 15:28:19 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	add_to_tail(t_stack *stack, int num)
{
	struct t_node	*current;

	current = (struct t_node *)malloc(sizeof(struct t_node));
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
}

int	stack_head_to_head(t_stack *dst, t_stack *src)
{
	struct t_node	*new;
	struct t_node	*old_node;

	if (!src || !src->head)
		return (-1);
	new = malloc(sizeof(struct t_node));
	if (!new)
		return (-1);
	new->number = src->head->number;
	new->rank = src->head->rank;
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
}

int	move_head_to_tail(t_stack *stack)
{
	struct t_node	*tmp;

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

int	move_tail_to_head(t_stack *stack)
{
	struct t_node	*tmp;

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

int	swap(t_stack *stack)
{
	long long	tmp_num;
	long long	tmp_rank;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	tmp_num = stack->head->number;
	stack->head->number = stack->head->next->number;
	stack->head->next->number = tmp_num;
	tmp_rank = stack->head->rank;
	stack->head->rank = stack->head->next->rank;
	stack->head->next->rank = tmp_rank;
	return (0);
}
