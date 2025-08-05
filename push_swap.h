/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaoulea <ppaoulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:36:02 by ppaoulea          #+#    #+#             */
/*   Updated: 2025/08/01 13:47:29 by ppaoulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

void	first_sort(t_node **stack_a, t_node **stack_b);
void	free_stack(t_node **stack);
int		is_sorted(t_node *a);
void	last_sort(t_node **stack_a, t_node **stack_b);
int		main(int ac, char **av);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	push_swap(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	take_arguments(int ac, char **av, t_node **stack_a);
int		stack_size(t_node *stack);
void	assign_indexes(t_node *stack);
int		steps_from_head(t_node *head, t_node *target);
int		steps_to_top(t_node *head, t_node *target);
t_node	*find_target_in_a(t_node *stack_a, int b_index);
void	move_nodes_to_top(t_node **stack_a, t_node **stack_b, t_node *b_node);
void	exit_error(void);
int		is_duplicate(t_node *stack, int value);
int		is_valid_number(char *str);
void	push_back(t_node **stack, int value);
int		safe_atoi(char *str);
#endif
