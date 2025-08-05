/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaoulea <ppaoulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:30:06 by ppaoulea          #+#    #+#             */
/*   Updated: 2025/08/03 14:30:43 by ppaoulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_core(t_node **s)
{
	t_node	*first;
	t_node	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	last = *s;
	while (last->next)
		last = last->next;
	*s = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **stack_a)
{
	rotate_core(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate_core(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_core(stack_a);
	rotate_core(stack_b);
	write(1, "rr\n", 3);
}
