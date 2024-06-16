/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:55:50 by marvin            #+#    #+#             */
/*   Updated: 2024/06/16 15:38:32 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	push_swap(t_stack *a, t_stack *b)
{
	push(a, b);
	min_max(a);
	min_max(b);
	big_push(a, b);
	min_max(b);
	easy_sort(a);
	big_push(b, a);
	min_max(a);
	rotator(r_until_top(a->min_add, a), 0, a, b);
	return ;
	
}

void	easy_sort(t_stack *s)
{
	if (s->stack[s->top] > s->stack[s->top + 1]
		&& s->stack[s->top + 1] > s->stack[s->bot])
	{
		rotate(s);
		rotate(s);
		return ;
	}
	else if (s->stack[s->top] > s->stack[s->top + 1]
		&& s->stack[s->top + 1] < s->stack[s->bot]
		&& s->stack[s->bot] < s->stack[s->top])
		r_rotate(s);
	else if (s->stack[s->top] > s->stack[s->top + 1]
		&& s->stack[s->top + 1] < s->stack[s->bot]
		&& s->stack[s->bot] > s->stack[s->top])
		swap(s);
	else if (s->stack[s->top] < s->stack[s->top + 1]
		&& s->stack[s->top] > s->stack[s->bot])
		rotate(s);
	return ;
}
