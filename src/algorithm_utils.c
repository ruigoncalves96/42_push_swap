/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:22 by randrade          #+#    #+#             */
/*   Updated: 2024/11/25 17:14:31 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_smallest_node(t_list **stack)
{
	t_list		*node;
	t_list		*smallest_node;
	int			nbr;

	node = *stack;
	nbr = node->nbr;
	smallest_node = node;
	while (node)
	{
		if (node->nbr < nbr)
		{
			nbr = node->nbr;
			smallest_node = node;
		}
		node = node->next;
	}
	return (smallest_node);
}

unsigned int	ft_update_stack_index(t_list **stack)
{
	t_list	*node;
	int		len;
	int		index;

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

void	ft_move_to_top(t_list **stack_a, t_list **stack_b, t_list *node, char c)
{
	while (node->previous)
	{
		if (node->before_meridian == true)
		{
			if (c == 'A')
				ft_rotate(stack_a, stack_b, RA);
			else if (c == 'B')
				ft_rotate(stack_a, stack_b, RB);
		}
		else
		{
			if (c == 'A')
				ft_reverse_rotate(stack_a, stack_b, RRA);
			else if (c == 'B')
				ft_reverse_rotate(stack_a, stack_b, RRB);
		}
	}
}
