/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:10:31 by thomvan-          #+#    #+#             */
/*   Updated: 2024/05/27 15:24:15 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	pusher(t_stack a, t_stack b)
{
	int	bmax;
	int	bmin;
	int	i;
	
	bmax = 0;
	bmin = b->stack[b->top];
	while (a->count > 3)
	{
		i = 0;
		while ((i - 1) < b->size)
		{
			i++;
			if (b->stack[i] > bmax)
				bmax = b->stack[i];
			if (b->stack[i] < bmin)
				bmin = b->stack[i];	
		}
		if (a->stack[top] > bmax || a->stack[top] < bmin )
			until_top()
	}
}

int	until_top(int addrs, t_stack stak)
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
