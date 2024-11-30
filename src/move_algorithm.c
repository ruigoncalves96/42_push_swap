/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:22 by randrade          #+#    #+#             */
/*   Updated: 2024/11/29 23:51:56 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_find_target(t_list *node_b, t_list **stack_a)
{
	t_list		*node_a;
	long		target_dif;	
	long		temp_dif;

	node_a = *stack_a;
	target_dif = 0;
	while (node_a)
	{
		if (node_b->nbr < node_a->nbr)
		{
			temp_dif = (long)node_a->nbr - (long)node_b->nbr;
			if (temp_dif < target_dif || target_dif == 0)
			{
				target_dif = temp_dif;
				node_b->target = node_a;
			}
		}
		node_a = node_a->next;
	}
	if (target_dif == 0)
		node_b->target = ft_get_smallest_node(stack_a);
}

static void	ft_get_move_cost(t_list *node_b, t_stack_info *stack_info)
{
	node_b->move_cost = 0;
	if (node_b->before_meridian == true)
		node_b->move_cost = node_b->index;
	else
		node_b->move_cost = stack_info->b_len - node_b->index;
	if (node_b->target->before_meridian == true)
		node_b->move_cost += node_b->target->index;
	else
		node_b->move_cost += stack_info->a_len - node_b->target->index;
}

static t_list	*ft_find_cheapest_move(t_list **stack_a, t_list **stack_b,
				t_stack_info *stack_info)
{
	t_list	*node_b;
	t_list	*cheapest_node;

	node_b = *stack_b;
	cheapest_node = NULL;
	while (node_b)
	{
		ft_find_target(node_b, stack_a);
		ft_get_move_cost(node_b, stack_info);
		if (!cheapest_node || node_b->move_cost < cheapest_node->move_cost)
			cheapest_node = node_b;
		node_b = node_b->next;
	}
	return (cheapest_node);
}

void	ft_move_algorithm(t_list **stack_a, t_list **stack_b,
				t_stack_info *stack_info)
{
	t_list			*node;

	node = NULL;
	while (*stack_b)
	{
		node = ft_find_cheapest_move(stack_a, stack_b, stack_info);
		ft_move_to_top(stack_b, node, stack_info, 'B');
		ft_move_to_top(stack_a, node->target, stack_info, 'A');
		ft_push(stack_a, stack_b, stack_info, PA);
	}
}
