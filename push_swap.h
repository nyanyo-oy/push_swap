/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:47:53 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 16:10:59 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

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
}	t_stack;

typedef struct PushSwap
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_pushswap;

long long		add_to_tail(t_stack *stack, int num);

int				stack_head_to_head(t_stack *dst, t_stack *src);//push
int				move_tail_to_head(t_stack *Stack);//reverse_rotate
int				move_head_to_tail(t_stack *Stack);//rotate
int				swap(t_stack *stack);


void			sa(t_pushswap *ps);
void			sb(t_pushswap *ps);
void			ss(t_pushswap *ps);

void			pa(t_pushswap *ps);
void			pb(t_pushswap *ps);

void			ra(t_pushswap *ps);
void			rb(t_pushswap *ps);
void			rr(t_pushswap *ps);

void			rra(t_pushswap *ps);
void			rrb(t_pushswap *ps);
void			rrr(t_pushswap *ps);

long long		add_to_tail(t_stack *stack, int num);
int				stack_head_to_head(t_stack *dst, t_stack *src);
int				move_head_to_tail(t_stack *stack);
int				move_tail_to_head(t_stack *stack);
int				swap(t_stack *stack);

long long		count_elements(t_pushswap *ps);
bool			is_already_sorted(t_pushswap *ps);
bool			has_duplicate(t_pushswap *ps, long long num);
bool			is_int_num(const char *nptr);
long long		ft_atoll(const char *nptr);


void			radix_lsd(t_pushswap *ps);
long long		*bubble(long long *rank, int elements);
int				ranking_nodes(t_pushswap *ps);

void			elements_are_two(t_pushswap *ps);
void			elements_are_three(t_pushswap *ps);
void			elements_are_four(t_pushswap *ps);
void			elements_are_five(t_pushswap *ps);

// void			debug_print_stack_a(t_pushswap *ps);
