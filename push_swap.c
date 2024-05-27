/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:55:50 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 14:34:36 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int i;
	
	i = a->size;
	push(a, b);
	pusher(a, b);
	easy_sort(a);
	
	
}

void	easy_sort(t_stack *s)
{
	if (s->stack[s->top] < s->stack[s->top + 1] && s->stack[s->top + 1] < s->stack[s->bot])
		return;
	if (s->stack[s->top] > s->stack[s->top + 1] && s->stack[s->top + 1] > s->stack[s->bot])
	{
		rotate(s);
		rotate(s);
		return;
	}
	if (s->stack[s->top] > s->stack[s->top + 1] &&
		s->stack[s->top + 1] < s->stack[s->bot] && s->stack[s->bot] < s->stack[s->top])
	{
		r_rotate(s);
		return;
	}
	if (s->stack[s->top] > s->stack[s->top + 1] &&
		s->stack[s->top + 1] < s->stack[s->bot] && s->stack[s->bot] > s->stack[s->top])
	{
		swap(s);
		return;
	}
	if (s->stack[s->top] < s->stack[s->top + 1] && s->stack[s->top] > s->stack[s->bot])
	{
		rotate(s);
		return;
	}
}