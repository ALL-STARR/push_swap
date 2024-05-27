/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:58:45 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 13:16:39 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	push(t_stack *src, t_stack *dst)
{
	if (is_empty(src))
		return (0);
	dst->bot++;
	dst->count++;
	dst->stack[dst->bot] = src->stack[src->bot];
	src->stack[src->bot] = 0;
	src->bot--;
	src->count--;
	ft_printf("p%c\n", dst->name);
	return (1);
}

int	swap(t_stack *stk)
{
	int	buf;

	if (is_empty(stk))
		return (0);
	buf = stk->stack[stk->bot];
	stk->stack[stk->bot] = stk->stack[stk->bot - 1];
	stk->stack[stk->bot - 1] = buf;
	ft_printf("s%c\n", stk->name);
	return (1);
}

int	rotate(t_stack *st)
{
	int	buff;

	st->bot = (st->bot + st->size + 1) % st->size;
	st->top = (st->top + st->size + 1) % st->size;
	ft_printf("r%c\n", st->name);
	return (1);
}

int	r_rotate(t_stack *st)
{
	int	buff;

	st->bot = (st->bot + st->size - 1) % st->size;
	st->top = (st->top + st->size - 1) % st->size;
	ft_printf("rr%c\n", st->name);
	return (1);
}
