/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:22 by randrade          #+#    #+#             */
/*   Updated: 2024/11/26 18:22:38 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_find_target(t_list *node_b, t_list **stack_a)
{
	t_list	*node_a;
	int		target_dif;	
	int		temp_dif;

	node_a = *stack_a;
	target_dif = 0;
	while (node_a)
	{
		if (node_b->nbr < node_a->nbr)
		{
			temp_dif = node_a->nbr - node_b->nbr;
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

static void	ft_get_move_cost(t_list *node_b, unsigned int stack_a_len,
					unsigned int stack_b_len)
{
	if (node_b->before_meridian == true)
		node_b->move_cost = node_b->index;
	else
		node_b->move_cost = stack_b_len - node_b->index;
	if (node_b->target->before_meridian == true)
		node_b->move_cost += node_b->target->index;
	else
		node_b->move_cost += stack_a_len - node_b->target->index;
}

static t_list	*ft_find_cheapest_move(t_list **stack_a, t_list **stack_b,
			unsigned int stack_a_len, unsigned int stack_b_len)
{
	t_list	*node_b;
	t_list	*cheapest_node;

	node_b = *stack_b;
	cheapest_node = NULL;
	while (node_b)
	{
		ft_find_target(node_b, stack_a);
		ft_get_move_cost(node_b, stack_a_len, stack_b_len);
		if (!cheapest_node || node_b->move_cost < cheapest_node->move_cost)
			cheapest_node = node_b;
		node_b = node_b->next;
	}
	return (cheapest_node);
}

static void	ft_optimize_stack_a(t_list **stack_a, t_list **stack_b)
{
	unsigned int	size;
	int	*lis;
	int	i;

	size = ft_lstsize(*stack_a);
	lis = ft_lis(stack_a);
	i = 0;
	while (size)
	{
		if ((*stack_a)->nbr != lis[i])
			ft_push(stack_a, stack_b, PB);
		else
		{
			if (ft_is_sorted(*stack_a) == true)
			{
				free(lis);
				break;

			}
			ft_rotate(stack_a, stack_b, RA);
			i++;
		}
		size--;
	}
	free(lis);
}

void	ft_algorithm(t_list **stack_a, t_list **stack_b)
{
	t_list			*node;
	unsigned int	a_len;
	unsigned int	b_len;

	node = NULL;
	ft_optimize_stack_a(stack_a, stack_b);
	a_len = ft_update_stack_index(stack_a);
	b_len = ft_update_stack_index(stack_b);
	while (*stack_b)
	{
		node = ft_find_cheapest_move(stack_a, stack_b, a_len, b_len);
		ft_move_to_top(stack_a, stack_b, node, 'B');
		ft_move_to_top(stack_a, stack_b, node->target, 'A');
		ft_push(stack_a, stack_b, PA);
		a_len = ft_update_stack_index(stack_a);
		b_len = ft_update_stack_index(stack_b);
	}
	ft_move_to_top(stack_a, stack_b, ft_get_smallest_node(stack_a), 'A');
}
