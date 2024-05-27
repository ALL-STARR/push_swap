/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:30:58 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 13:21:36 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_S_H
# define PUSH_S_H

#include "libft.h"
#include "ft_printf.h"

typedef struct s_stack
{
	int		top;
	int 	bot;
	int		*stack;
	int 	size;
	int 	count;
	char	name;
}	t_stack;

int 	is_repeating(char **argm, int count);
int		is_num(char **argm);
t_stack *stack_init(int count);
void 	Astack_filler(t_stack *A, char **argm);
int 	is_empty(t_stack *st);
int		swap(t_stack *stk);
int		push(t_stack *src, t_stack *dst);
int		rotate(t_stack *st);
int		r_rotate(t_stack *st);
int		doubler(int (*f)(t_stack), t_stack a, t_stack b);
void	easy_sort(t_stack *s);
int		d_rotate(t_stack *st1, t_stack *st2);
int		d_r_rotate(t_stack *st1, t_stack *st2);

#endif