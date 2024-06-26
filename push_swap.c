/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:55:50 by marvin            #+#    #+#             */
/*   Updated: 2024/06/26 20:36:21 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_s.h"

void	push_swap(t_stack *a, t_stack *b)
{
	push(a, b);
	//ft_printf("a->bot is %d and = %d a->top is %d and is = %d\n", a->bot, a->stack[a->bot], a->top, a->stack[a->top]);
	stack_display(a);
	rotator(a, r_until_top(2, a));
	//ft_printf("a->bot is %d and = %d a->top is %d and is = %d\n", a->bot, a->stack[a->bot], a->top, a->stack[a->top]);
	//stack_display(a);
	stack_display(a);
	/*while(a->count > 3)
	{
		find_cheapest(a, b);
		organizer(a,b);
		push(a, b);
	}
	easy_sort(a);*/
	
	return ;
}

void	easy_sort(t_stack *s)
{
	if (s->stack[s->top] > s->stack[next_down(s, s->top)]
		&& s->stack[next_down(s, s->top)] > s->stack[next_down(s, s->top + 1)])
	{
		r_rotate(s, 1);
		swap(s);
	}
	else if (s->stack[s->top] > s->stack[next_down(s, s->top)]
		&& s->stack[next_down(s, s->top)] < s->stack[next_down(s, s->top + 1)]
		&& s->stack[next_down(s, s->top + 1)] < s->stack[s->top])
		r_rotate(s, 1);
	else if (s->stack[s->top] > s->stack[next_down(s, s->top)]
		&& s->stack[next_down(s, s->top)] < s->stack[next_down(s, s->top + 1)]
		&& s->stack[next_down(s, s->top + 1)] > s->stack[s->top])
		swap(s);
	else if (s->stack[s->top] < s->stack[next_down(s, s->top)]
		&& s->stack[s->top] > s->stack[next_down(s, s->top + 1)])
		rotate(s, 1);
	else if (s->stack[s->top] < s->stack[next_down(s, s->top)]
		&& s->stack[next_down(s, s->top + 1)] < s->stack[next_down(s, s->top)])
	{
		swap(s);
		r_rotate(s, 1);
	}
	return ;
}

int	next_up(t_stack *s, int add)
{
	if(s->count == 0)
		return (USER_ADDR_NULL);
	if(add == 0)
		return (s->size - 1);
	else
		return (add - 1);
}

int	next_down(t_stack *s, int add)
{
	if(s->count == 0)
		return (add);
	if(add == s->size - 1)
		return (0);
	else
		return (add + 1);
}

