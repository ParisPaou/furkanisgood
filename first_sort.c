/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaoulea <ppaoulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:35:52 by ppaoulea          #+#    #+#             */
/*   Updated: 2025/08/05 16:59:35 by ppaoulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// void first_sort(t_node stack_a, t_node stack_b)
// {
// 	int max_index;
// 	int push_index;
// 	int list_size;

//  	t_node current;
//  	list_size = stack_size(stack_a);
//  	max_index = list_size - 1;
//  	push_index = max_index / 2;
// 	assign_indexes(*stack_a);
//  	current = stack_a;
// 	while (stack_size(stack_a) > 3)
//  	{
// 		if (current->index <= push_index)
//  	{
// 		if (steps_from_head(stack_a, current) <= stack_size(stack_a) / 2)
//  		{
// 			while (stack_a != current)
// 				ra(stack_a);
// 		}
// 		else
//  		{
// 			while (stack_a != current)
// 				rra(stack_a);
//  		}
// 		pb(stack_a, stack_b);
//  		current = *stack_a;
//  		}
// 		else
//  		current = current->next;
//  	}
// }

void	first_sort(t_node **a, t_node **b)
{
	int pivot;	

	if (stack_size(*a) <= 3)
		return ;
	pivot = (stack_size(*a) / 2);
	assign_indexes(*a);
	while (stack_size(*a) != pivot)
	{
		if ((*a)->index <= pivot)
			pb(a, b);
		else
			ra(a);
	}
	return (first_sort(a, b));
}