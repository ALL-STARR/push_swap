/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:51:40 by marvin            #+#    #+#             */
/*   Updated: 2024/06/27 18:31:12 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	is_repeating(char **argm, int count)
{
	int	i;
	int	j;
	int	*checker;

	checker = malloc(sizeof(int) * (count + 1));
	i = 0;
	j = 0;
	while (argm[i] != 0)
	{
		checker[i] = ft_atoi(argm[i]);
		while (j < i)
		{
			if (checker[i] == checker[j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	free(checker);
	return (0);
}

int	is_num(char **argm)
{
	int	i;
	int	j;

	i = 0;
	while (argm[i] != 0)
	{
		j = 0;
		if (argm[i][j] == '-')
			j++;
		while (argm[i][j])
			if (!(ft_isdigit(argm[i][j++])))
				return (0);
		i++;
	}
	return (1);
}

t_stack	*stack_init(int count, char nam)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->size = count;
	s->stack = malloc(sizeof(int) * (count + 1));
	if (!s->stack)
		return (NULL);
	while (count)
	{
		s->stack[count - 1] = 0;
		count--;
	}
	s->top = 0;
	s->bot = 0;
	s->count = 0;
	s->name = nam;
	return (s);
}

int	astack_filler(t_stack *a, char **argm, int cntr)
{
	int	i;
	int	*check;

	i = 0;
	check = malloc(sizeof(int) * (cntr + 1));
	if (!check)
		return (0);
	while (argm[i] != 0)
	{
		a->stack[i] = ft_atoi(argm[i]);
		check[i] = ft_atoi(argm[i]);
		i++;
	}
	a->stack[i] = '\0';
	check[i] = '\0';
	ranker(check, a, cntr);
	a->count = cntr;
	a->bot = a->size - 1;
	return (1);
}

void	ranker(int *list, t_stack *a, int size)
{
	int	i;
	int	j;
	int	count_smaller;

	i = 0;
	while (i < size)
	{
		j = 0;
		count_smaller = 0;
		while (j < size)
			if (list[j++] <= list[i])
				count_smaller++;
		a->stack[i] = count_smaller;
		i++;
	}
	free(list);
}
