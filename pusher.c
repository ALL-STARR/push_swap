/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:10:31 by thomvan-          #+#    #+#             */
/*   Updated: 2024/07/01 17:12:53 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	rtt(int addrs, t_stack *stak)
{
	int	i;
	int	j;
	int	ref;

	i = 0;
	j = 0;
	ref = addrs;
	while (stak->stack[addrs] != stak->stack[stak->top])
	{
		addrs = next_down(stak, addrs);
		if (stak->stack[addrs] != 0)
			i++;
	}
	addrs = ref;
	while (stak->stack[addrs] != stak->stack[stak->top])
	{
		addrs = next_up(stak, addrs);
		if (stak->stack[addrs] != 0)
			j++;
	}
	if (i <= j)
		return (i);
	else
		return (-j);
}

t_moves	find_cheap(t_stack *a, t_stack *b)
{
	int	min;
	int	count;
	int adrs;
	t_moves	moves;

	min = a->count;
	count = min;
	adrs = a->top;
	moves.aadd = a->top;
	while (count)
	{
		if (a->stack[adrs] > b->max || a->stack[adrs] < b->min)
		{
			if (min > m_plus(rtt(adrs, a), b->max_add, b))
			{
				min = m_plus(rtt(adrs, a), b->max_add, b);
				moves.aadd = adrs;
				moves.badd = b->max_add;
			}
		}
		else if (min > m_plus(rtt(adrs, a), clo_val_up(a, b, adrs), b))
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

int	clo_val_up(t_stack *a, t_stack *b, int a_add)
{
	int	i;
	int j;
	int	index;

	i = b->top;
	j = 1;
	while (((a->stack[a_add] + j) < a->max) || ((a->stack[a_add] + j) < b->max))
	{
		while (i < b->count)
		{
			if(b->stack[i] == a->stack[a_add] + j)
				return (i);
			i = next_down(b, i);
		}
		j++;
	}
		return (b->top);
}

int m_plus(int min_m, int b_adrs, t_stack *b)
{
	int	a_amount;
	int b_amount;
	int	tot_amount;

	a_amount = min_m;
	b_amount = rtt(b_adrs, b);
	if (a_amount * b_amount)
		return (absolute((a_amount - b_amount)));
	else
		return (absolute(a_amount) + absolute(b_amount));
}