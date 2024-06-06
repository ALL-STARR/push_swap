/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:16:49 by thomvan-          #+#    #+#             */
/*   Updated: 2024/06/06 14:12:03 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	d_rotate(t_stack *st1, t_stack *st2)
{
	st1->bot = (st1->bot + st1->size + 1) % st1->size;
	st1->top = (st1->top + st1->size + 1) % st1->size;
	st2->bot = (st2->bot + st2->size + 1) % st2->size;
	st2->top = (st2->top + st2->size + 1) % st2->size;
	ft_printf("rr\n");
	return (1);
}

int	d_r_rotate(t_stack *st1, t_stack *st2)
{
	st1->bot = (st1->bot + st1->size - 1) % st1->size;
	st1->top = (st1->top + st1->size - 1) % st1->size;
	st2->bot = (st2->bot + st2->size - 1) % st2->size;
	st2->top = (st2->top + st2->size - 1) % st2->size;
	ft_printf("rrr\n");
	return (1);
}
