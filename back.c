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
	int	j;
	int	k;

	j = 1;
	while ((((a->stack[a_add] + j) <= a->max)
			|| ((a->stack[a_add] + j) <= b->max)))
	{
		i = b->top;
		k = b->count;
		while (k)
		{
			if (b->stack[i] == a->stack[a_add] + j)
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

void	b_pusher(t_stack *a, t_stack *b)
{
	int	add;

	min_max(b);
	if (a->stack[a->top] > b->max)
		add = b->min_add;
	else
		add = clo_val_up(a, b, a->top);
	if (b->top != add)
		rotator(b, rtt(add, b));
	push(a, b);
	return ;
}
