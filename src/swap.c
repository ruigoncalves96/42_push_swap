/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:52:42 by randrade          #+#    #+#             */
/*   Updated: 2024/11/30 00:00:02 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_s(t_list **stack)
{
	t_list	*first;

	first = NULL;
	if (!*stack || !(*stack)->next)
		return ;
	first = (*stack)->next;
	(*stack)->previous = first;
	(*stack)->next = first->next;
	if ((*stack)->next)
		(*stack)->next->previous = *stack;
	first->previous = NULL;
	first->next = *stack;
	*stack = first;
}

void	ft_swap(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info, int move)
{
	if (move == SA)
	{
		ft_s(stack_a);
		ft_putstr_fd("sa\n", 1);
		stack_info->a_len = ft_update_stack_index(stack_a);
	}
	else if (move == SB)
	{
		ft_s(stack_b);
		ft_putstr_fd("sb\n", 1);
		stack_info->b_len = ft_update_stack_index(stack_b);
	}
	else if (move == SS)
	{
		ft_s(stack_a);
		ft_s(stack_b);
		ft_putstr_fd("ss\n", 1);
		stack_info->a_len = ft_update_stack_index(stack_a);
		stack_info->b_len = ft_update_stack_index(stack_b);
	}
}
