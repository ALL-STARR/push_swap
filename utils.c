/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:04:58 by thomvan-          #+#    #+#             */
/*   Updated: 2024/06/27 17:57:55 by thomvan-         ###   ########.fr       */
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

void	stack_display(t_stack *s)
{
	int	adrs;
	int	count;

	count = s->count;
	adrs = s->top;
	ft_printf("%c :", s->name);
	while (count)
	{
		ft_printf(" %d", s->stack[adrs]);
		adrs = next_down(s, adrs);
		count--;
	}
	ft_printf("\n");
}

void	true_display(t_stack *s)
{
	int	count;
	int	i;

	i = 0;
	count = s->size;
	ft_printf("true %c : ", s->name);
	while(count)
	{
		ft_printf("%d ", s->stack[i]);
		i++;
		count--;
	}
	ft_printf("\n");
}