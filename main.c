/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:22:52 by marvin            #+#    #+#             */
/*   Updated: 2024/06/26 20:31:58 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**set;
	int		arcount;
	int		flag;

	set = argv + 1;
	arcount = argc;
	flag = 0;
	if (arcount == 1)
		return (0);
	if (arcount == 2)
		set = ft_reader(set, argv, &arcount, &flag);
	if (is_invalid(set, arcount))
		return (0);
	if (initiator(&a, &b, arcount, set))
		return (-1);
	dispatcher(a, b, arcount, set);
	freeer(a, b, flag, set);
	return (0);
}

int	is_invalid(char **set, int arcount)
{
	if (!is_num(set) || is_repeating(set, arcount - 1) || is_too_much(set))
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int	initiator(t_stack **a, t_stack **b, int arcount, char **set)
{
	*a = stack_init(arcount - 1, 'a');
	*b = stack_init(arcount - 1, 'b');
	if (!a || !b)
		return (1);
	astack_filler(*a, set, arcount - 1);
	return (0);
}

void	freeer(t_stack *a, t_stack *b, int fl, char **set)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	if (fl)
		free(set);
}

char	**ft_reader(char **set, char **argv, int *arcount, int *flag)
{
	set = ft_split(argv[1], ' ');
	if (!set)
		return (NULL);
	*arcount = dtab_len(set);
	*flag = 1;
	return (set);
}
