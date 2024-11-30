/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:22 by randrade          #+#    #+#             */
/*   Updated: 2024/11/29 23:57:55 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_biggest_lis(t_list **stack)
{
	t_list			*temp;
	t_list			*biggest_lis;
	unsigned int	lis;

	temp = *stack;
	biggest_lis = NULL;
	lis = 0;
	while (temp)
	{
		if (temp->lis > lis)
		{
			lis = temp->lis;
			biggest_lis = temp;
		}
		temp = temp->next;
	}
	return (biggest_lis);
}

static void	ft_calculate_lis(t_list **stack)
{
	t_list	*i;
	t_list	*j;

	i = (*stack)->next;
	j = *stack;
	while (j)
	{
		j->lis = 1;
		j = j->next;
	}
	j = *stack;
	while (i)
	{
		if (j->nbr < i->nbr)
		{
			if (j->lis + 1 > i->lis)
				i->lis = j->lis + 1;
		}
		j = j->next;
		if (j == i)
		{
			j = *stack;
			i = i->next;
		}
	}
}

static void	ft_get_lis_array(t_list *lis_node)
{
	unsigned int	size;

	size = lis_node->lis;
	while (size > 0)
	{
		if (lis_node->lis == size)
		{
			lis_node->is_lis = true;
			size--;
		}
		else
			lis_node->is_lis = false;
		lis_node = lis_node->previous;
	}
}

void	ft_lis(t_list **stack, t_stack_info *stack_info)
{
	t_list	*lis_node;

	ft_calculate_lis(stack);
	lis_node = ft_get_biggest_lis(stack);
	stack_info->lis_size = lis_node->lis;
	ft_get_lis_array(lis_node);
}
