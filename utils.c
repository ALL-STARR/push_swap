/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:04:58 by thomvan-          #+#    #+#             */
/*   Updated: 2024/06/14 20:21:56 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	absolute(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void	first_push(t_stack *a, t_stack *b)
{
	int	i;
	int	a_rot;
	int	b_rot;
	t_moves	cheap;

	i = 0;
	while (i <= (a->size - 3))
	{
		cheap = find_cheapest(a, b);
		a_rot = r_until_top(cheap_add, a);
		if (cheap.badd != b->max_add)
			b_rot = r_untiltop(find_closest_val_up(a, b, cheap.aadd), b);
		else
			b_rot = r_until_top(b->max_add, b);
		rotator(a_rot, b_rot, a, b);
		push(a, b);
		i++;
	}
}

void	rotator(int rot_a, int rot_b, t_stack *a, t_stack *b)
{
	while (rot_a != 0 || rot_b != 0)
	{
		if (rot_a < 0)
		{
			r_rotations(&rot_a, &rot_b, a, b);
		}
		if (rot_a > 0)
		{
			f_rotations(&rot_a, &rot_b, a, b);
		}
	}
	return ;
}

void	r_rotations(int *rota, int *rotb, t_stack *a, t_stack *b)
{
	while (*rot_a != 0 && *rot_b != 0)
	{
		d_r_rotate(a, b);
		*rot_a++;
		*rot_b++;
	}
	if (rot_a != 0)
	{
		rotate(a);
		*rot_a++;
	}
	if (rot_b != 0)
	{
		rotate(b);
		*rot_b++;
	}
	return ;
}

void	f_rotations(int *rota, int *rotb, t_stack *a, t_stack *b)
{
	while (*rot_a != 0 && *rot_b != 0)
	{
		d_r_rotate(a, b);
		*rot_a--;
		*rot_b--;
	}
	if (rot_a != 0)
	{
		rotate(a);
		*rot_a--;
	}
	if (rot_b != 0)
	{
		rotate(b);
		*rot_b--;
	}
	return ;
}
