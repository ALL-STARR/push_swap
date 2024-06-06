/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:30:58 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 16:22:44 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_S_H
# define PUSH_S_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int		top;
	int		bot;
	int		*stack;
	int		size;
	int		count;
	char	name;
	int		max;
	int		min;
	int		max_add;
	int		min_add;
}	t_stack;

typedef struct s_moves
{
	int		a_n_moves;
	int		b_n_moves;
	int		index;
}	t_moves;

int		is_repeating(char **argm, int count);
int		is_num(char **argm);
t_stack	*stack_init(int count);
void	astack_filler(t_stack *A, char **argm);
int		is_empty(t_stack *st);
int		swap(t_stack *stk);
int		push(t_stack *src, t_stack *dst);
int		rotate(t_stack *st);
int		r_rotate(t_stack *st);
void	easy_sort(t_stack *s);
int		d_rotate(t_stack *st1, t_stack *st2);
int		d_r_rotate(t_stack *st1, t_stack *st2);
void	min_max(t_stack *st);
int		find_closest_val_up(t_stack *a, t_stack *b, int a_add);
int		absolute(int num);
int		r_until_top(int addrs, t_stack *stak);
int		find_cheapest(t_stack *a, t_stack *b);

#endif