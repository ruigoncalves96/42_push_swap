/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:52:42 by randrade          #+#    #+#             */
/*   Updated: 2024/11/12 14:15:47 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	ft_s(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->previous->previous = *stack;
	if ((*stack)->previous->next)
		(*stack)->previous->next = (*stack)->next;
	(*stack)->next = (*stack)->previous;
	(*stack)->previous = NULL;
}

void	ft_swap(t_list **stack_a, t_list **stack_b, int move)
{
	if (move == SA)
	{
		ft_s(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (move == SB)
	{
		ft_s(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	else if (move == SS)
	{
		ft_s(stack_a);
		ft_s(stack_b);
		ft_putstr_fd("ss\n", 1);
	}
}
