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

	if (argc == 1)
		return (0);
	if (!is_num(argv) || is_repeating(argv, argc - 1) || is_too_much(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	a = stack_init(argc - 1, 'a');
	b = stack_init(argc - 1, 'b');
	if (!a || !b)
		return (-1);
	astack_filler(a, argv, argc - 1);
	stack_display(a);
	if (argc == 3 && (atoi(argv[1]) > atoi(argv[2])))
		swap(a);
	if (argc == 4)
		easy_sort(a);
	if (argc > 4)
		push_swap(a, b);
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	return (0);
}
