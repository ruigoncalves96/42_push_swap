/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:53:12 by randrade          #+#    #+#             */
/*   Updated: 2024/12/03 12:10:18 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static bool	ft_p(t_list **to_stack, t_list **from_stack)
{
	t_list	*temp;

	temp = NULL;
	if (!(*from_stack))
		return (false);
	temp = (*from_stack)->next;
	if (temp)
		temp->previous = NULL;
	ft_lstadd_first(to_stack, *from_stack);
	*from_stack = temp;
	return (true);
}

void	ft_push(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info, int move)
{
	(void)stack_info;
	if (move == PA)
		ft_p(stack_a, stack_b);
	else if (move == PB)
		ft_p(stack_b, stack_a);
}
