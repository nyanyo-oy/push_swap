/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:47:53 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/14 12:08:31 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft-42/libft.h"

typedef struct Node
{
	int		number;
	struct Node	*next;
	struct Node	*prev;
}	Node;

typedef struct Stack
{
	Node	*head;
	Node	*tail;
}	t_Stack;

typedef struct PushSwap
{
	t_Stack	stack_a;
	t_Stack	stack_b;
	// int		operation_count;
}	t_PushSwap;

int		add_to_tail(t_Stack *stack, int num);

int		stack_head_to_head(t_Stack *dst, t_Stack *src);//push
int		move_tail_to_head(t_Stack *Stack);//reverse_rotate
int		move_head_to_tail(t_Stack *Stack);//rotate
int		swap(t_Stack *stack);

// void	print_newline(t_PushSwap *ps);

int		sa(t_PushSwap *ps);
int		sb(t_PushSwap *ps);
int		ss(t_PushSwap *ps);

int		pa(t_PushSwap *ps);
int		pb(t_PushSwap *ps);

int		ra(t_PushSwap *ps);
int		rb(t_PushSwap *ps);
int		rr(t_PushSwap *ps);

int		rra(t_PushSwap *ps);
int		rrb(t_PushSwap *ps);
int		rrr(t_PushSwap *ps);

int	search_min(t_PushSwap *ps);
int	search_max(t_PushSwap *ps);
void	nomalize(t_PushSwap *ps, int min);
void	de_nomalize(t_PushSwap *ps, int min);

int		ft_atoi(const char *nptr);
bool	is_int_num(const char *nptr);

void	radix_lsd(t_PushSwap *ps);

bool	is_already_sorted(t_PushSwap *ps);

int		elements_are_one(t_PushSwap *ps);
int		elements_are_two(t_PushSwap *ps);
int		elements_are_three(t_PushSwap *ps);
int		elements_are_four(t_PushSwap *ps);
int		elements_are_five(t_PushSwap *ps);

// PushSwap *ps stack_arv(char **arv);