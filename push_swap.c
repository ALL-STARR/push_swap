/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:55:50 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 16:26:56 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size;
	push(a, b);
	pusher(a, b);
	min_max(a);
	min_max(b);
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
