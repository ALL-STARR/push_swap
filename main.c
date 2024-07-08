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
	{
		set = ft_split(argv[1], ' ');
		arcount = dtab_len(set);
		flag = 1;
	}
	if (!is_num(set) || is_repeating(set, arcount - 1) || is_too_much(set))
	{
		ft_printf("Error\n");
		return (0);
	}
	a = stack_init(arcount - 1, 'a');
	b = stack_init(arcount - 1, 'b');
	if (!a || !b)
		return (-1);
	astack_filler(a, set, arcount - 1);
	if (arcount == 3 && (atoi(set[0]) > atoi(set[1])))
		swap(a);
	if (arcount == 4)
		easy_sort(a);
	if (arcount > 4)
		push_swap(a, b);
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	if (flag)
		free(set);
	return (0);
}
