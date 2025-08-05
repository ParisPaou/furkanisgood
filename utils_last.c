/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaoulea <ppaoulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:52:39 by ppaoulea          #+#    #+#             */
/*   Updated: 2025/08/03 14:22:15 by ppaoulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_to_top(t_node *head, t_node *target)
{
	int		size;
	int		forward_steps;
	t_node	*current;

	size = stack_size(head);
	forward_steps = 0;
	current = head;
	while (current && current != target)
	{
		current = current->next;
		forward_steps++;
	}
	if (forward_steps <= size / 2)
		return (forward_steps);
	return (forward_steps - size);
}

static	t_node	*find_min_above(t_node *a, int b_index)
{
	t_node	*best;
	int		best_idx;

	best = NULL;
	best_idx = __INT_MAX__;
	while (a)
	{
		if (a->index > b_index && a->index < best_idx)
		{
			best_idx = a->index;
			best = a;
		}
		a = a->next;
	}
	return (best);
}

static	t_node	*find_min_node(t_node *a)
{
	t_node	*best;
	int		best_idx;

	best = NULL;
	best_idx = __INT_MAX__;
	while (a)
	{
		if (a->index < best_idx)
		{
			best_idx = a->index;
			best = a;
		}
		a = a->next;
	}
	return (best);
}

t_node	*find_target_in_a(t_node *stack_a, int b_index)
{
	t_node	*target;

	target = find_min_above(stack_a, b_index);
	if (!target)
		target = find_min_node(stack_a);
	return (target);
}

void	move_nodes_to_top(t_node **stack_a, t_node **stack_b, t_node *b_node)
{
	t_node	*target_a;
	int		steps_b;
	int		steps_a;

	if (!stack_a || !stack_b || !*stack_b || !b_node)
		return ;
	target_a = find_target_in_a(*stack_a, b_node->index);
	while (*stack_b != b_node)
	{
		steps_b = steps_to_top(*stack_b, b_node);
		if (steps_b < 0)
			rrb(stack_b);
		else
			rb(stack_b);
	}
	while (*stack_a != target_a)
	{
		steps_a = steps_to_top(*stack_a, target_a);
		if (steps_a < 0)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pa(stack_a, stack_b);
}
