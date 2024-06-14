/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:30:58 by marvin            #+#    #+#             */
/*   Updated: 2024/06/14 21:00:56 by thomvan-         ###   ########.fr       */
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
	int		aadd;
	int		badd;
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
void	r_rotations(int *rota, int *rotb, t_stack *a, t_stack *b);
void	f_rotations(int *rota, int *rotb, t_stack *a, t_stack *b);
void	first_push(t_stack *a, t_stack *b);
void	rotator(int rot_a, int rot_b, t_stack *a, t_stack *b);

#endif