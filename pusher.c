/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:10:31 by thomvan-          #+#    #+#             */
/*   Updated: 2024/05/29 18:27:02 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	pusher(t_stack a, t_stack b)
{
	int	bmax;
	int	bmaxadd;
	int	bmin;
	int	i;
	
	bmax = b->stack[b->top];
	bmin = bmax;
	while (a->count > 3)
	{
		i = 0;
		while ((i - 1) < b->size)
		{
			i++;
			if (b->stack[i] > bmax)
			{
				bmaxadd = i;
				bmax = b->stack[i];
			}
			if (b->stack[i] < bmin)
				bmin = b->stack[i];	
		}
	}
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

t_moves	comparator(t_stack a, t_stack b, int bmaxaddress, int bmax, int bmin)
{
	t_moves	n_moves;
	int		min_moves;
	int		i;

	i = 0;
	min_moves = a->size;
	n_moves->b_n_moves = r_until_top(bmaxaddress, b);
	while (i <= a->size)
	{
		if(a->stack[i] < bmin || a->stack[i] > bmax)
		{
			if (min_moves > absolute(r_until_top(i, a)))
				min_moves = r_until_top(i, a);
		}
		else if (min_moves > absolute())
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

int	find_closest(t_stack a, t_stack b, int a_add)
{
	int closest;
	int	clo_add;
	int	i;
	
	i = 0;
	while (closest < a->stack[a_add])
	{
		closest = b->stack[i];
		i++;
	}
	i = 0;
	while (i <= a->size)
	{
		i++;
		if (b->stack[i] > a->stack[a_add])
		{
			if (b->stack[i] < closest)
			{
				clo_add = i;
				closest = b->stack[i];
			}
		}
	}
	return (i);
}