/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:55:50 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 17:36:57 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	push_swap(t_stack *a, t_stack *b)
{
	push(a, b);
	while (a->count > 3)
		pusher(a, b);
	easy_sort(a);
	rotator(b, rtt(b->max_add, b));
	while (b->count > 0)
		b_pusher(b, a);
	min_max(a);
	rotator(a, rtt(a->min_add, a));
	return ;
}

void	easy_sort(t_stack *s)
{
	if (s->stack[s->top] > s->stack[n_d(s, s->top)]
		&& s->stack[n_d(s, s->top)] > s->stack[n_d(s, n_d(s, s->top))])
	{
		r_rotate(s, 1);
		swap(s);
	}
	else if (s->stack[s->top] > s->stack[n_d(s, s->top)]
		&& s->stack[n_d(s, s->top)] < s->stack[n_d(s, n_d(s, s->top))]
		&& s->stack[n_d(s, n_d(s, s->top))] < s->stack[s->top])
		r_rotate(s, 1);
	else if (s->stack[s->top] > s->stack[n_d(s, s->top)]
		&& s->stack[n_d(s, s->top)] < s->stack[n_d(s, n_d(s, s->top))]
		&& s->stack[n_d(s, n_d(s, s->top))] > s->stack[s->top])
		swap(s);
	else if (s->stack[s->top] < s->stack[n_d(s, s->top)]
		&& s->stack[s->top] > s->stack[n_d(s, n_d(s, s->top))])
		rotate(s, 1);
	else if (s->stack[s->top] < s->stack[n_d(s, s->top)]
		&& s->stack[n_d(s, n_d(s, s->top))] < s->stack[n_d(s, s->top)])
	{
		swap(s);
		r_rotate(s, 1);
	}
	return ;
}

int	next_up(t_stack *s, int add)
{
	if (s->count == 0)
		return (0);
	if (add == 0)
		return (s->size - 1);
	else
		return (add - 1);
}

int	n_d(t_stack *s, int add)
{
	if (s->count == 0)
		return (add);
	if (add == s->size - 1)
		return (0);
	else
		return (add + 1);
}
