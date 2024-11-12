/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:53:39 by randrade          #+#    #+#             */
/*   Updated: 2024/11/12 14:19:47 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	ft_r(t_list **stack)
{
	t_list	*temp;

	if (!(*stack)->next)
		return ;
	temp = (*stack)->next;
	ft_lstadd_last(stack, *stack);
	*stack = temp;
	(*stack)->previous = NULL;
}

void	ft_rotate(t_list **stack_a, t_list **stack_b, int move)
{
	if (move == RA)
	{
		ft_r(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (move == RB)
	{
		ft_r(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	else if (move == RR)
	{
		ft_r(stack_a);
		ft_r(stack_b);
		ft_putstr_fd("rr\n", 1);
	}
}
