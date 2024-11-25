/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:54:38 by randrade          #+#    #+#             */
/*   Updated: 2024/11/25 17:23:13 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rr(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	second_last = last->previous;
	ft_lstadd_first(stack, last);
	second_last->next = NULL;
}

void	ft_reverse_rotate(t_list **stack_a, t_list **stack_b, int move)
{
	if (move == RRA)
	{
		ft_rr(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (move == RRB)
	{
		ft_rr(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (move == RRR)
	{
		ft_rr(stack_a);
		ft_rr(stack_b);
		ft_putstr_fd("rrr\n", 1);
	}
}
