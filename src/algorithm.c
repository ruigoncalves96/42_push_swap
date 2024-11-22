/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:22 by randrade          #+#    #+#             */
/*   Updated: 2024/11/22 18:05:44 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_list	*ft_get_biggest_node(t_list **stack)
{
	t_list		*node;
	t_list		*biggest_node;
	int		nbr;

	node = *stack;
	biggest_node = NULL;
	nbr = 0;
	while (node)
	{
		if (node->nbr > nbr)
		{
			nbr = node->nbr;
			biggest_node = node;
		}
		node = node->next;
	}
	return (biggest_node);
}

static unsigned int	ft_update_node_index(t_list **stack)
{
	t_list	*node;
	int	len;
	int	index;

	node = *stack;
	len = ft_lstsize(*stack);
	index = 0;
	while (node)
	{
		node->index = index;
		if (index <= len / 2)
			node->before_meridian = true;
		else
			node->before_meridian = false;
		node = node->next;
		index++;
	}
	return (len);
}

static void	ft_find_target(t_list *node_a, t_list **stack_b)
{
	t_list		*node_b;
	int		target_dif;	
	int		temp_dif;

	node_b = *stack_b;
	target_dif = 0;
	while (node_b)
	{
		if (node_a->nbr > node_b->nbr)
		{
			temp_dif = node_a->nbr - node_b->nbr;
			if (temp_dif < target_dif || target_dif == 0)
			{
				target_dif = temp_dif;
				node_a->target = node_b;
			}
		}
		node_b = node_b->next;
	}
	if (target_dif == 0)
		node_a->target = ft_get_biggest_node(stack_b);
}

static void	ft_get_move_cost(t_list *node_a, unsigned int stack_a_len,
					unsigned int stack_b_len)
{
	if (node_a->before_meridian == true)
		node_a->move_cost = node_a->index;
	else
		node_a->move_cost = stack_a_len - node_a->index;
	if (node_a->target->before_meridian == true)
		node_a->move_cost += node_a->target->index;
	else
		node_a->move_cost += stack_b_len - node_a->target->index;
}

static t_list	*ft_check_moves(t_list **stack_a, t_list **stack_b,
			unsigned int stack_a_len, unsigned int stack_b_len)
{
	t_list	*node_a;
	t_list	*cheapest_node;
	
	node_a = *stack_a;
	cheapest_node = NULL;
	while (node_a)
	{
		ft_find_target(node_a, stack_b);
		ft_get_move_cost(node_a, stack_a_len, stack_b_len);
		if (!cheapest_node || node_a->move_cost < cheapest_node->move_cost)
			cheapest_node = node_a;
		node_a = node_a->next;
	}
	return (cheapest_node);
}

static void	ft_move_to_top(t_list **stack_a, t_list **stack_b, t_list *node, char c)
{
	while (node->previous)
	{
		if (node->before_meridian == true)
		{
			if (c == 'A')
				ft_rotate(stack_a, stack_b, RA);
			else if	(c == 'B')
				ft_rotate(stack_a, stack_b, RB);
		}
		else
		{
			if (c == 'A')
				ft_reverse_rotate(stack_a, stack_b, RRA);
			else if	(c == 'B')
				ft_reverse_rotate(stack_a, stack_b, RRB);
		}
	}
}

void	ft_algorithm(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	unsigned int	stack_a_len;
	unsigned int	stack_b_len;

	node = NULL;
	stack_a_len = 0;
	stack_b_len = 0;
	ft_push(stack_a, stack_b, PB);
	while (*stack_a)
	{
		stack_a_len = ft_update_node_index(stack_a);
		stack_b_len = ft_update_node_index(stack_b);
		node = ft_check_moves(stack_a, stack_b, stack_a_len, stack_b_len);
		ft_move_to_top(stack_a, stack_b, node, 'A');
		ft_move_to_top(stack_a, stack_b, node->target, 'B');
		ft_push(stack_a, stack_b, PB);
	}
	ft_move_to_top(stack_a, stack_b, ft_get_biggest_node(stack_b), 'B');
	while (*stack_b)
		ft_push(stack_a, stack_b, PA);
}
//	Move first 2 numbers to B
//		Check If are in descendent order
//			IF FALSE -> Put in descendent order
//	While (stack_a exists)
//		-Get Nodes data of A & B
//			target_node -> Check which node has the closest smallest number
//			move_cost -> calculate the cost of going to top of target_node
//		-Check which node has the cheapest move_cost
//		-Execute that Node move
//	Move biggest number to top
//	Move Stack B to A
