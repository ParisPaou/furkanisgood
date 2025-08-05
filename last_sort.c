/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaoulea <ppaoulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:52:21 by ppaoulea          #+#    #+#             */
/*   Updated: 2025/08/05 17:04:38 by ppaoulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static void	rotate_together(t_node **a, t_node **b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b);
		(*ca)++;
		(*cb)++;
	}
}

static void	bring_to_top_one(t_node **s, t_node *t,
		void (*rot)(t_node **), void (*rrot)(t_node **))
{
	int	cost;

	cost = steps_to_top(*s, t);
	while (*s != t)
	{
		if (cost < 0)
			rrot(s);
		else
			rot(s);
	}
}

static void	find_best_pair(t_node *a, t_node *b,
		t_node **best_a, t_node **best_b)
{
	t_node	*cur;
	t_node	*tar;
	int		tot;
	int		best;

	*best_a = NULL;
	*best_b = NULL;
	best = INT_MAX;
	cur = b;
	while (cur)
	{
		tar = find_target_in_a(a, cur->index);
		tot = int_abs(steps_to_top(a, tar))
			+ int_abs(steps_to_top(b, cur));
		if (tot < best)
		{
			best = tot;
			*best_a = tar;
			*best_b = cur;
		}
		cur = cur->next;
	}
}

// void	last_sort(t_node **stack_a, t_node **stack_b)
// {
// 	// t_node	*ideal_a;
// 	// t_node	*ideal_b;
// 	// int		ca;
// 	// int		cb;

// 	first_sort(stack_a, stack_b);
// 	// while (*stack_b)
// 	// {
// 	// 	find_best_pair(*stack_a, *stack_b, &ideal_a, &ideal_b);
// 	// 	if (!ideal_a || !ideal_b)
// 	// 		break ;
// 	// 	ca = steps_to_top(*stack_a, ideal_a);
// 	// 	cb = steps_to_top(*stack_b, ideal_b);
// 	// 	rotate_together(stack_a, stack_b, &ca, &cb);
// 	// 	bring_to_top_one(stack_a, ideal_a, ra, rra);
// 	// 	bring_to_top_one(stack_b, ideal_b, rb, rrb);
// 	// 	pa(stack_a, stack_b);
// 	// }
// }
