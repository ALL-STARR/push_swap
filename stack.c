/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:35:03 by marvin            #+#    #+#             */
/*   Updated: 2024/06/26 18:23:11 by thomvan-         ###   ########.fr       */
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
	min = st->stack[st->top];
	max = min;
	while (i < st->count)
	{
		while(st->stack[i] == 0)
			i++;
		if(st->stack[i] < min)
		{
			min = st->stack[i];
			st->min_add = i;
		}
		if(st->stack[i] > max)
		{
			max = st->stack[i];
			st->max_add = i;
		}
		i++;
	}
	st->max = max;
	st->min = min;
	return ;
}
