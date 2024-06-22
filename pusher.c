/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:10:31 by thomvan-          #+#    #+#             */
/*   Updated: 2024/06/22 13:07:50 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	r_until_bot(int addrs, t_stack *stak)
{
	int	size;
	int	rotates;
	int	i;
	int	j;

	ft_printf("addrs is = %d | ", addrs);
	size = stak->count;
	rotates = 0;
	i = 0;
	j = 0;
	while (stak->stack[(stak->bot + size + i - 1) % size] != stak->stack[addrs])
		i++;
	//ft_printf("r_til_bot_i = %d\n", i);
	while (stak->stack[(stak->bot + size - j - 1) % size] != stak->stack[addrs])
		j++;
	ft_printf("r_til_bot_j = %d\n", j);	
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
	while (i <= a->count - 1)
	{
		if (absolute(a_min_moves) > absolute(r_until_bot(i, a)))
		{
			a_min_moves = r_until_bot(i, a);
			ft_printf("a_min_moves = %d\n", a_min_moves);
			if (a->stack[i] < b->min || a->stack[i] > b->max)
				b_min_moves = r_until_bot(b->max_add, b);
			else
				b_min_moves = r_until_bot(find_closest_val_up(a, b, i), b);
			ft_printf("b_min_moves = %d\n", b_min_moves);
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
	how_far = a->max;
	i = 0;
	while (i <= b->size)
	{
		if (how_far > absolute((a->stack[a_add] - b->stack[i])))
		{
			if (a->stack[a_add] > b->stack[i])
			{
				how_far = absolute((a->stack[a_add] - b->stack[i]));
				clo_add = i;
			}
		}
		i++;
	}
	return (clo_add);
}
