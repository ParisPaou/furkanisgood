/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaoulea <ppaoulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:55:31 by ppaoulea          #+#    #+#             */
/*   Updated: 2025/07/19 16:38:33 by ppaoulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_split_and_push(char **strings, t_node **stack_a)
{
	int		j;
	int		number;

	j = 0;
	while (strings[j])
	{
		if (!is_valid_number(strings[j]))
			exit_error();
		number = safe_atoi(strings[j]);
		if (is_duplicate(*stack_a, number))
			exit_error();
		push_back(stack_a, number);
		free(strings[j]);
		j++;
	}
	free(strings);
}

void	take_arguments(int ac, char **av, t_node **stack_a)
{
	int		i;
	char	**strings;

	i = 1;
	while (i < ac)
	{
		strings = ft_split(av[i], ' ');
		if (!strings)
			exit_error();
		handle_split_and_push(strings, stack_a);
		i++;
	}
}
