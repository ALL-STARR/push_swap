/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:10:31 by thomvan-          #+#    #+#             */
/*   Updated: 2024/06/26 22:32:23 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	r_until_top(int addrs, t_stack *stak)
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
	{
		ft_printf("%d\n", i);
		return (i);
	}
	else
	{
		ft_printf("%d\n", -j);
		return (-j);
	}
}

void	find_cheapest(t_stack *a, t_stack *b)
{
	int	index;
	int	min;
	
	min_max(a);
	min_max(b);
	index = a->top;
	while (a->count)
	{
		if (a->stack[index] > b->max)
			if (r_until_top(index, a) * r_until_top(b->max_add, b))
				min = index;
		else if (a->stack[index] < b->min)
			if (r_until_top(index, a) * r_until_top(b->max_add, b))
				min = index;
		else
			if (r_until_top(index, a) * r_until_top(find_closest_val_up(a, b, index), b))
				min = index;
		index = next_down(a, index);
	}
}

int	find_closest_val_up(t_stack *a, t_stack *b, int a_add)
{
	int	i;
	int	index;

	i = 0;
	while (i < b->count)
	{
		if(b->stack[i] == a->stack[a_add] + 1)
			return (i);
		i++;
	}
	return (-1);
}
