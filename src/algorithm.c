/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:22 by randrade          #+#    #+#             */
/*   Updated: 2024/11/28 18:21:39 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_optimize_stack_a(t_list **stack_a, t_list **stack_b)
{
	unsigned int	size;
	unsigned int	lis_size;
	int	*lis;
	int	i;

	size = ft_lstsize(*stack_a);
	lis = ft_lis(stack_a);
	lis_size = (ft_get_biggest_lis(stack_a))->lis;
	i = 0;
	while (size)
	{
		if ((*stack_a)->nbr != lis[i] || lis_size == 0)
			ft_push(stack_a, stack_b, PB);
		else
		{
			ft_rotate(stack_a, stack_b, RA);
			i++;
			lis_size--;
		}
		size--;
	}
	free(lis);
}

void	ft_sort_3(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = ft_get_biggest_node(stack_a);
	if (node->index == 1)
		ft_reverse_rotate(stack_a, stack_b, RRA);
	else if (node->index == 0)
		ft_rotate(stack_a, stack_b, RA);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		ft_swap(stack_a, stack_b, SA);
}

void	ft_sort_4_5(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) != 3)
		ft_push(stack_a, stack_b, PB);
	ft_sort_3(stack_a, stack_b);
	ft_move_algorithm(stack_a, stack_b);
	ft_move_to_top(stack_a, stack_b, ft_get_smallest_node(stack_a), 'A');
}

void	ft_algorithm(t_list **stack_a, t_list **stack_b)
{
	ft_optimize_stack_a(stack_a, stack_b);
	ft_move_algorithm(stack_a, stack_b);
	ft_move_to_top(stack_a, stack_b, ft_get_smallest_node(stack_a), 'A');
}
