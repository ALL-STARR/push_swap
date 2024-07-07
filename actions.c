/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:58:45 by marvin            #+#    #+#             */
/*   Updated: 2024/06/26 19:54:28 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	push(t_stack *src, t_stack *dst)
{
	int	dest;

	dest = next_up(dst, dst->top);
	dst->stack[next_up(dst, dst->top)] = src->stack[src->top];
	dst->top = dest;
	dst->count++;
	src->stack[src->top] = 0;
	src->count--;
	src->top = n_d(src, src->top);
	ft_printf("p%c\n", dst->name);
	return (1);
}

int	swap(t_stack *stk)
{
	int	buf;

	buf = stk->stack[stk->top];
	stk->stack[stk->top] = stk->stack[n_d(stk, stk->top)];
	stk->stack[n_d(stk, stk->top)] = buf;
	ft_printf("s%c\n", stk->name);
	return (1);
}

void	r_rotate(t_stack *stk, int print)
{
	if (stk->count == stk->size)
	{
		stk->bot = stk->top;
		stk->top = n_d(stk, stk->top);
	}
	else
	{
		stk->bot = n_d(stk, stk->bot);
		stk->stack[stk->bot] = stk->stack[stk->top];
		stk->stack[stk->top] = 0;
		stk->top = n_d(stk, stk->top);
	}
	if (print)
		ft_printf("r%c\n", stk->name);
}

void	rotate(t_stack *stk, int print)
{
	if (stk->count == stk->size)
	{
		stk->top = stk->bot;
		stk->bot = next_up(stk, stk->bot);
	}
	else
	{
		stk->top = next_up(stk, stk->top);
		stk->stack[stk->top] = stk->stack[stk->bot];
		stk->stack[stk->bot] = 0;
		stk->bot = next_up(stk, stk->bot);
	}
	if (print)
		ft_printf("rr%c\n", stk->name);
}
