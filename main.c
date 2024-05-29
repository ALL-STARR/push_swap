/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:22:52 by marvin            #+#    #+#             */
/*   Updated: 2024/05/29 18:03:00 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	if (argc < 3 || !is_num(argv) || is_repeating(argv, argc - 1))
	{
		ft_printf("wrong input! Please retry with numbers");
		return (0);
	}
	a = stack_init(argc - 1, 'a');
	b = stack_init(argc - 1, 'b');
	Astack_filler(a, argv, argc - 1);
	push_swap(t_stack *a, t_stack *b)
	free(a->stack);
	free(b->stack);
}