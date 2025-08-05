/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaoulea <ppaoulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:43:12 by ppaoulea          #+#    #+#             */
/*   Updated: 2025/08/03 14:20:34 by ppaoulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min_node(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	t_node	*min;

	while (stack_size(*stack_a) > 3)
	{
		min = find_min_node(*stack_a);
		if (steps_from_head(*stack_a, min) <= stack_size(*stack_a) / 2)
		{
			while (*stack_a != min)
				ra(stack_a);
		}
		else
		{
			while (*stack_a != min)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
