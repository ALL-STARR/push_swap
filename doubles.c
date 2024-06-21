/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:16:49 by thomvan-          #+#    #+#             */
/*   Updated: 2024/06/21 18:02:09 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	d_rotate(t_stack *st1, t_stack *st2)
{
	st1->bot = (st1->bot + st1->count + 1) % st1->count;
	st1->top = (st1->top + st1->count + 1) % st1->count;
	st2->bot = (st2->bot + st2->count + 1) % st2->count;
	st2->top = (st2->top + st2->count + 1) % st2->count;
	ft_printf("rr\n");
	return (1);
}

int	d_r_rotate(t_stack *st1, t_stack *st2)
{
	st1->bot = (st1->bot + st1->count - 1) % st1->count;
	st1->top = (st1->top + st1->count - 1) % st1->count;
	st2->bot = (st2->bot + st2->count - 1) % st2->count;
	st2->top = (st2->top + st2->count - 1) % st2->count;
	ft_printf("rrr\n");
	return (1);
}
