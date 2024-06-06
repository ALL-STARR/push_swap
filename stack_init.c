/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:51:40 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 14:28:58 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_s.h"

int	is_repeating(char **argm, int count)
{
	int	i;
	int	j;
	int	*checker;

	checker = malloc(sizeof(int) * (count + 1));
	i = 0;
	j = 0;
	while (argm[i] != '\0')
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
	j = 0;
	while (argm[i] != 0)
	{
		while (argm[i][j] != 0)
		{
			if (!ft_isdigit(argm[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*stack_init(int count, char nam)
{
	t_stack	*s;

	s->size = count;
	s->stack = malloc(sizeof(int) * (count + 1));
	s->top = 0;
	s->bot = 0;
	s->counter = 0;
	s->name = nam;
	return (s);
}

void	astack_filler(t_stack *A, char **argm, int cntr)
{
	int	i;

	i = 0;
	while (argm[i] != '\0')
	{
		A->stack[i] = ft_atoi(argm[i]);
		i++;
	}
	A->stack[i] = '\0';
	A->count = cntr;
	return ;
}
