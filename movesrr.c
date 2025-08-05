/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaoulea <ppaoulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:11:58 by ppaoulea          #+#    #+#             */
/*   Updated: 2025/08/03 14:32:10 by ppaoulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_core(t_node **s)
{
	t_node	*last;
	t_node	*pre_last;

	if (!s || !*s || !(*s)->next)
		return ;
	last = *s;
	pre_last = *s;
	while (last->next)
		last = last->next;
	while (pre_last->next->next)
		pre_last = pre_last->next;
	pre_last->next = NULL;
	last->next = *s;
	*s = last;
}

void	rra(t_node **stack_a)
{
	reverse_rotate_core(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate_core(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_core(stack_a);
	reverse_rotate_core(stack_b);
	write(1, "rrr\n", 4);
}
