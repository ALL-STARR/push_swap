/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:16:49 by thomvan-          #+#    #+#             */
/*   Updated: 2024/07/01 16:24:37 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	d_rotate(t_stack *st1, t_stack *st2)
{
	rotate(st1, 0);
	rotate(st2, 0);
	ft_printf("rr\n");
	return (1);
}

int	d_r_rotate(t_stack *st1, t_stack *st2)
{
	r_rotate(st1, 0);
	r_rotate(st2, 0);
	ft_printf("rrr\n");
	return (1);
}

void	rotator(t_stack *stc, int amount)
{
	if (amount == 0)
		return ;
	while (amount > 0)
	{
		rotate(stc, 1);
		amount--;
	}
	while (amount < 0)
	{
		r_rotate(stc,1);
		amount++;
	}
}

void	doubler(t_stack *a, t_stack *b, int am1, int am2)
{
	if (am1 * am2)
	{
		while (am1 && am2)
		{
			if (am1 > 0)
			{
				d_rotate(a, b);
				am1--;
				am2--;
			}
			else if (am1 < 0)
			{
				d_r_rotate(a, b);
				am1++;
				am2++;
			}
		}
	}
	rotator(a, am1);
	rotator(b, am2);
	return ;
}