/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:10:31 by thomvan-          #+#    #+#             */
/*   Updated: 2024/06/06 16:19:28 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	pusher(t_stack a, t_stack b)
{
	int	bmaxadd;
	int	i;

	i = 0;
	min_max(b);
	min_max(a);
	comparator(a, b, b->max_add);
}

int	r_until_top(int addrs, t_stack stak)
{
	int	size;
	int	rotates;
	int	i;
	int	j;

	size = stak->size;
	rotates = 0;
	i = 0;
	j = 0;
	while (stak->stack[(stak->top + size + i) % size] != stak->stack[addrs])
		i++;
	while (stak->stack[(stak->top + size - j) % size] != stak->stack[addrs])
		j++;
	if (i >= j)
		return (i);
	else
		return (-j);
}

int	find_cheapest(t_stack a, t_stack b, int bmaxaddress)
{
	int		a_min_moves;
	int		b_min_moves;
	int		bup_add;
	int		cheapest_add;
	int		i;

	i = 0;
	a_min_moves = a->size;
	while (i <= a->size)
	{
		if (absolute(a_min_moves) > absolute(r_until_top(i, a)))
		{
			a_min_moves = r_until_top(i, a);
			if (a->stack[i] < b->min || a->stack[i] > b->max)
				b_min_moves = r_until_top(b->max_add, b);
			else
				b_min_moves = r_until_top(find_closest_val_up(a, b, i), b);
		}
		if ((b_min_moves * a_min_moves) > 0)
			cheapest_add = i;
		i++;
	}
	return (cheapest_add);
}

int	find_closest_val_up(t_stack a, t_stack b, int a_add)
{
	int	closest;
	int	clo_add;
	int	how_far;
	int	i;

	closest = b->stack[0];
	how_far = b->size;
	i = 0;
	while (i <= b->size)
	{
		if (how_far > absolute((a->stack[a_add] - b->stack[i])))
		{
			if (a->stack[a_add] < b->stack[i])
			{
				how_far = absolute((a->stack[a_add] - b->stack[i]));
				clo_add = i;
			}
		}
		i++;
	}
	return (clo_add);
}
