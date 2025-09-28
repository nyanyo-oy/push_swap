/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:47:53 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/12 13:53:08 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

# define SUCCESS 0
# define FAILURE 1

typedef struct t_node
{
	long long		number;
	long long		rank;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

typedef struct t_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct t_pushswap
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
bool			is_value_duplicated(t_pushswap *ps, long long num);
bool			is_integer(const char *nptr);
long long		ft_atoll(const char *nptr);

void			radix_lsd(t_pushswap *ps);
long long		*bubble(long long *rank, int elements);
int				ranking_nodes(t_pushswap *ps);

void			elements_are_two(t_pushswap *ps);
void			elements_are_three(t_pushswap *ps);
void			elements_are_four(t_pushswap *ps);
void			elements_are_five(t_pushswap *ps);

void			free_stack(t_stack *stack);
int				pushswap(char **ptrr, int elements);
void			end_program(int exit_status, t_pushswap *ps);

#endif