/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:47:53 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 14:40:40 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft-42/libft.h"

typedef struct t_node
{
	long long	number;
	long long	rank;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

typedef struct Stack
{
	t_node	*head;
	t_node	*tail;
}	t_Stack;

typedef struct PushSwap
{
	t_Stack	stack_a;
	t_Stack	stack_b;
}	t_PushSwap;

long long		add_to_tail(t_Stack *stack, int num);

int				stack_head_to_head(t_Stack *dst, t_Stack *src);//push
int				move_tail_to_head(t_Stack *Stack);//reverse_rotate
int				move_head_to_tail(t_Stack *Stack);//rotate
int				swap(t_Stack *stack);


void			sa(t_PushSwap *ps);
void			sb(t_PushSwap *ps);
void			ss(t_PushSwap *ps);

void			pa(t_PushSwap *ps);
void			pb(t_PushSwap *ps);

void			ra(t_PushSwap *ps);
void			rb(t_PushSwap *ps);
void			rr(t_PushSwap *ps);

void			rra(t_PushSwap *ps);
void			rrb(t_PushSwap *ps);
void			rrr(t_PushSwap *ps);

// long long		search_min(t_PushSwap *ps);
// long long		search_max(t_PushSwap *ps);
// void			nomalize(t_PushSwap *ps, long long min);
// void			de_nomalize(t_PushSwap *ps, long long min);

long long		ft_atoll(const char *nptr);
bool			is_int_num(const char *nptr);

void			radix_lsd(t_PushSwap *ps);

bool			is_already_sorted(t_PushSwap *ps);
bool			has_duplicate(t_PushSwap *ps, long long num);


void				elements_are_two(t_PushSwap *ps);
void				elements_are_three(t_PushSwap *ps);
void				elements_are_four(t_PushSwap *ps);
void				elements_are_five(t_PushSwap *ps);

// void			debug_print_stack_a(t_PushSwap *ps);
