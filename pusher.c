/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:10:31 by thomvan-          #+#    #+#             */
/*   Updated: 2024/06/03 16:52:48 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	pusher(t_stack a, t_stack b)
{
	int	bmaxadd;
	int	i;
	
	b->max = b->stack[b->top];
	b->min = b->max;
	i = 0;
	while ((i - 1) < b->size)
	{
		i++;
		if (b->stack[i] > b->max)
		{
			bmaxadd = i;
			b->max = b->stack[i];
		}
		if (b->stack[i] < b->min)
			b->min = b->stack[i];	
	}
	min_max(a);
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

t_moves	comparator(t_stack a, t_stack b, int bmaxaddress)
{
	t_moves	n_moves;
	int		a_min_moves;
	int		b_min_moves;
	int		i;

	i = 0;
	a_min_moves = a->size;
	b_min_moves = b->size;
	n_moves->b_n_moves = r_until_top(bmaxaddress, b);
	while (i <= a->size)
	{
		if (a->stack[i] < b->min || a->stack[i] > b->max)
		{
			if (a_min_moves > absolute(r_until_top(i, a)))
				a_min_moves = r_until_top(i, a);
		}
		else
		{
			
		}
		i++;
	}
	
}

int	absolute(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	find_closestup(t_stack a, t_stack b, int a_add)
{
	int closest;
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