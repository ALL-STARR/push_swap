/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:22:52 by marvin            #+#    #+#             */
/*   Updated: 2024/05/13 18:22:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	if (argc < 3 || !is_num(argv) || is_repeating(argv, argc - 1))
	{
		//print error message
		return (0);
	}
	a = stack_init(argc - 1);
	b = stack_init(argc - 1);
	Astack_filler(a, argv);
	//push_swap(t_stack *a, t_stack *b)
	free(a->stack);
	free(b->stack);
}