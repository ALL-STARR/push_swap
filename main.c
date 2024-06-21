/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:22:52 by marvin            #+#    #+#             */
/*   Updated: 2024/06/21 17:26:54 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 3 || !is_num(argv) || is_repeating(argv, argc - 1))
	{
		ft_printf("wrong input! Please retry with numbers and without doubles");
		return (0);
	}
	a = stack_init(argc - 1, 'a');
	b = stack_init(argc - 1, 'b');
	if (!a || !b)
		return (-1);
	astack_filler(a, argv, argc - 1);
	if (argc == 3 && (atoi(argv[1]) > atoi(argv[2])))
		swap(a);
	else if (argc == 4)
		easy_sort(a);
	
	ft_printf("%d\n", a->bot);
	
	if (argc > 4)
		push_swap(a, b);
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	return (0);
}
