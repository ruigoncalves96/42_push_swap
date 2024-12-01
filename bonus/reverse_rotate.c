/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:54:38 by randrade          #+#    #+#             */
/*   Updated: 2024/12/01 00:39:41 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

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

void	ft_reverse_rotate(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info, int move)
{
	(void)stack_info;
	if (move == RRA)
		ft_rr(stack_a);
	else if (move == RRB)
		ft_rr(stack_b);
	else if (move == RRR)
	{
		ft_rr(stack_a);
		ft_rr(stack_b);
	}
}
