/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:58:45 by marvin            #+#    #+#             */
/*   Updated: 2024/05/13 18:58:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	push(t_stack *src, t_stack *dst)
{
	if (is_empty(src))
		return (0);
	dst->bot++;
	dst->count++;
	dst->stack[dst->bot] = src->stack[src->bot];
	src->stack[src->bot] = 0;
	src->bot--;
	src->count--;
}

int	swap(t_stack *stk)
{
	int	buf;

	if (is_empty(stk))
		return (0);
	buf = stk->stack[stk->bot];
	stk->stack[stk->bot] = stk->stack[stk->bot - 1];
	stk->stack[stk->bot - 1] = buf;
	return (1);
}

void	rotate(t_stack *st)
{
	int	buff;

	st->bot = (st->bot + st->size + 1) % st->size;
	st->top = (st->top + st->size + 1) % st->size;
}

void	r_rotate(t_stack *st)
{
	int	buff;

	st->bot = (st->bot + st->size - 1) % st->size;
	st->top = (st->top + st->size - 1) % st->size;
}

void	doubler(void *f(), t_stack a, t_stack b)
{
	*f(a);
	*f(b);
}