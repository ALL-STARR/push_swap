/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:30:58 by marvin            #+#    #+#             */
/*   Updated: 2024/05/13 18:30:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_S_H
# define PUSH_S_H

typedef struct s_stack
{
	int	top;
	int bot;
	int	*stack;
	int size;
	int count;
}	t_stack;

int 	is_repeating(char **argm, int count);
int		is_num(char **argm);
t_stack *stack_init(int count);
void 	Astack_filler(t_stack *A, char **argm);
int 	is_full(t_stack *s);
int 	is_empty(t_stack *st);

#endif