/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 23:04:29 by marvin            #+#    #+#             */
/*   Updated: 2024/07/05 23:04:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	clo_val_up(t_stack *a, t_stack *b, int a_add)
{
	int	i;
	int j;
	int	k;

	j = 1;
	while ((((a->stack[a_add] + j) <= a->max ) || ((a->stack[a_add] + j) <= b->max)))
	{
		i = b->top;
		k = b->count;
		while (k)
		{
			if(b->stack[i] == a->stack[a_add] + j)
			{
				return (i);
			}
			i = next_down(b, i);
			k--;
		}
		j++;
	}
		return (b->top);
}

t_moves	b_find_cheap(t_stack *a, t_stack *b)
{
	int	min;
	int	count;
	int adrs;
	t_moves	moves;

	min = a->count;
	count = min;
	adrs = a->top;
	moves.aadd = a->top;
	moves.badd = clo_val_up(a, b, a->top);
	while (count)
	{
		if (a->stack[adrs] > b->max || a->stack[adrs] < b->min)
		{
			if (min > m_plus(rtt(adrs, a), b->min_add, b))
			{
				min = m_plus(rtt(adrs, a), b->min_add, b);
				moves.aadd = adrs;
				moves.badd = b->min_add;
			}
		}
		if (min > m_plus(rtt(adrs, a), clo_val_up(a, b, adrs), b))
		{
			min = m_plus(rtt(adrs, a), clo_val_up(a, b, adrs), b);
			moves.aadd = adrs;
			moves.badd = clo_val_up(a, b, adrs);
		}	
		adrs = next_down(a, adrs);
		count--;
	}
	return (moves);
}

void	b_pusher(t_stack *a, t_stack *b)
{
	t_moves	m;
	min_max(a);
	min_max(b);
	m = b_find_cheap(a, b);
	doubler(a, b, rtt(m.aadd, a), rtt(m.badd, b));
	push(a, b);
	return ;
}