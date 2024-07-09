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
		addrs = n_d(stak, addrs);
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

t_moves	f_find_cheap(t_stack *a, t_stack *b)
{
	int		min;
	int		count;
	int		adrs;
	t_moves	moves;

	min = a->count;
	count = min;
	adrs = a->top;
	moves.aadd = a->top;
	moves.badd = clo_val_down(a, b, a->top);
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
		else if (min > m_plus(rtt(adrs, a), clo_val_down(a, b, adrs), b))
		{
			min = m_plus(rtt(adrs, a), clo_val_down(a, b, adrs), b);
			moves.aadd = adrs;
			moves.badd = clo_val_down(a, b, adrs);
		}
		adrs = n_d(a, adrs);
		count--;
	}
	return (moves);
}

int	clo_val_down(t_stack *a, t_stack *b, int a_add)
{
	int	i;
	int	j;
	int	k;

	j = 1;
	while (((a->stack[a_add] - j) > a->min || (a->stack[a_add] - j) > b->min))
	{
		i = b->top;
		k = b->count;
		while (k)
		{
			if (b->stack[i] == a->stack[a_add] - j)
				return (i);
			i = n_d(b, i);
			k--;
		}
		j++;
	}
	return (b->top);
}

int	m_plus(int min_m, int b_adrs, t_stack *b)
{
	int	a_amount;
	int	b_amount;

	a_amount = min_m;
	b_amount = rtt(b_adrs, b);
	return (calc(a_amount, b_amount));
}

int	calc(int am1, int am2)
{
	int	i;

	i = 0;
	if (am1 * am2)
	{
		while (am1 && am2)
		{
			if (am1 > 0)
			{
				am1--;
				am2--;
				i++;
			}
			else if (am1 < 0)
			{
				am1++;
				am2++;
				i++;
			}
		}
	}
	return (i + absolute(am1) + absolute(am2));
}
