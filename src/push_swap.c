/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:30 by randrade          #+#    #+#             */
/*   Updated: 2024/11/25 18:41:01 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_print_stack(t_list *stack)
{
	t_list	*i;

	i = stack;
	while (i)
	{
		ft_printf("nbr = %d\n", i->nbr);
		ft_printf("index %u\n", i->index);
		ft_printf("move_cost %u\n", i->move_cost);
		ft_printf("meridian %d\n", i->before_meridian);
		ft_printf("traget->nbr %d\n\n", i->target->nbr);
		i = i->next;
	}
}*/
static void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	int		nbr_len;

	node = NULL;
	nbr_len = ft_lstsize(*stack_a);
	if (nbr_len == 2)
		ft_swap(stack_a, stack_b, SA);
	else if (nbr_len == 3)
	{
		node = ft_get_biggest_node(stack_a);
		ft_update_stack_index(stack_a);
		if (node->index == 1)
			ft_reverse_rotate(stack_a, stack_b, RRA);
		else if (node->index == 0)
			ft_rotate(stack_a, stack_b, RA);
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			ft_swap(stack_a, stack_b, SA);
	}
	else
		ft_algorithm(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	ft_convert_and_parse(argv + 1, &stack_a);
	if (ft_is_sorted(stack_a) == false)
		ft_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
