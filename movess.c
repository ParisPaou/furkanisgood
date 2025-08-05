/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movess.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaoulea <ppaoulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:34:46 by ppaoulea          #+#    #+#             */
/*   Updated: 2025/08/03 14:33:21 by ppaoulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_core(t_node **s)
{
	t_node	*first;
	t_node	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa(t_node **stack_a)
{
	swap_core(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	swap_core(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_core(stack_a);
	swap_core(stack_b);
	write(1, "ss\n", 3);
}
