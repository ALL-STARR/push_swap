/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:35:03 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 17:28:46 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	min_max(t_stack *st)
{
	int		add;
	int		count;

	count = st->count;
	add = st->top;
	st->min = st->stack[add];
	st->min_add = add;
	st->max = 0;
	while (count)
	{
		if (st->stack[add] < st->min)
		{
			st->min = st->stack[add];
			st->min_add = add;
		}
		if (st->stack[add] > st->max)
		{
			st->max = st->stack[add];
			st->max_add = add;
		}
		add = n_d(st, add);
		count--;
	}
	return ;
}

void	pusher(t_stack *a, t_stack *b)
{
	t_moves	m;

	min_max(a);
	min_max(b);
	m = f_find_cheap(a, b);
	doubler(a, b, rtt(m.aadd, a), rtt(m.badd, b));
	push(a, b);
	return ;
}

static int	spacer(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

long int	big_atoi(const char *str)
{
	long int	i;
	long int	res;
	long int	minus;
	long int	previous;

	res = 0;
	minus = 1;
	i = spacer((char *)str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		previous = res;
		res = (res * 10) + (str[i] - 48);
		if (previous > res && minus == 1)
			return (-1);
		if (previous > res && minus == -1)
			return (0);
		i++;
	}
	return (res * minus);
}

int	is_too_much(char **arv)
{
	int			i;
	long int	val;

	i = 0;
	while (arv[i])
	{
		if (big_atoi(arv[i]) > 2147483647 || big_atoi(arv[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}
