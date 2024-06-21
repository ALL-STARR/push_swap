/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:35:03 by marvin            #+#    #+#             */
/*   Updated: 2024/06/21 16:44:35 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	is_empty(t_stack *st)
{
	return (st->count == 0);
}

void	min_max(t_stack *st)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = st->stack[0];
	max = min;
	while (i <= st->size)
	{
		if (st->stack[i] < min)
		{
			min = st->stack[i];
			st->min_add = i;
		}
		if (st->stack[i] > max)
		{
			max = st->stack[i];
			st->max_add = i;
		}
		i++;
	}
	st->max = max;
	st->min = min;
}
