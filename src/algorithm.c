/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:22 by randrade          #+#    #+#             */
/*   Updated: 2024/11/29 23:58:24 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **stack_a, t_list **stack_b, t_stack_info *stack_info)
{
	t_list	*node;

	node = ft_get_biggest_node(stack_a);
	if (node->index == 1)
		ft_reverse_rotate(stack_a, stack_b, stack_info, RRA);
	else if (node->index == 0)
		ft_rotate(stack_a, stack_b, stack_info, RA);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		ft_swap(stack_a, stack_b, stack_info, SA);
}

void	ft_sort_4_5(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info)
{
	while (stack_info->a_len != 3)
		ft_push(stack_a, stack_b, stack_info, PB);
	ft_sort_3(stack_a, stack_b, stack_info);
	ft_move_algorithm(stack_a, stack_b, stack_info);
	ft_move_to_top(stack_a, ft_get_smallest_node(stack_a), stack_info, 'A');
}

void	ft_algorithm(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info)
{
	ft_optimize_stacks(stack_a, stack_b, stack_info);
	ft_move_algorithm(stack_a, stack_b, stack_info);
	ft_move_to_top(stack_a, ft_get_smallest_node(stack_a), stack_info, 'A');
}
