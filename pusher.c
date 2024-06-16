/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:10:31 by thomvan-          #+#    #+#             */
/*   Updated: 2024/06/16 15:55:18 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	r_until_bot(int addrs, t_stack *stak)
{
	int	size;
	int	rotates;
	int	i;
	int	j;

	size = stak->size;
	rotates = 0;
	i = 0;
	j = 0;
	while (stak->stack[(stak->bot + size + i) % size] != stak->stack[addrs])
		i++;
	while (stak->stack[(stak->bot + size - j) % size] != stak->stack[addrs])
		j++;
	if (i >= j)
		return (i);
	else
		return (-j);
}

t_moves	find_cheapest(t_stack *a, t_stack *b)
{
	int			a_min_moves;
	int			b_min_moves;
	t_moves		targets;
	int			i;

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
		{
			targets.aadd = i;
			targets.badd = find_closest_val_up(a, b, i);
		}
		i++;
	}
	return (targets);
}

int	find_closest_val_up(t_stack *a, t_stack *b, int a_add)
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
