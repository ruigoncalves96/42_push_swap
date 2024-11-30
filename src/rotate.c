/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:53:39 by randrade          #+#    #+#             */
/*   Updated: 2024/11/29 23:56:22 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_r(t_list **stack)
{
	t_list	*temp;

	if (!(*stack)->next)
		return (false);
	temp = (*stack)->next;
	ft_lstadd_last(stack, *stack);
	*stack = temp;
	(*stack)->previous = NULL;
	return (true);
}

void	ft_rotate(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info, int move)
{
	if (move == RA)
	{
		if (ft_r(stack_a) == true)
		{
			ft_putstr_fd("ra\n", 1);
			stack_info->a_len = ft_update_stack_index(stack_a);
		}
	}
	else if (move == RB)
	{
		if (ft_r(stack_b) == true)
		{
			ft_putstr_fd("rb\n", 1);
			stack_info->b_len = ft_update_stack_index(stack_b);
		}
	}
	else if (move == RR)
	{
		if (ft_r(stack_a) == true && ft_r(stack_b) == true)
		{
			ft_putstr_fd("rr\n", 1);
			stack_info->a_len = ft_update_stack_index(stack_a);
			stack_info->b_len = ft_update_stack_index(stack_b);
		}
	}
}
