/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:53:39 by randrade          #+#    #+#             */
/*   Updated: 2024/12/01 00:39:30 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

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
	(void)stack_info;
	if (move == RA)
		ft_r(stack_a);
	else if (move == RB)
		ft_r(stack_b);
	else if (move == RR)
	{
		ft_r(stack_a);
		ft_r(stack_b);
	}
}
