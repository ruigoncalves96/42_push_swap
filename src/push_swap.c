/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:30 by randrade          #+#    #+#             */
/*   Updated: 2024/11/28 16:59:40 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_list *stack)
{
	t_list	*i;

	i = stack;
	while (i)
	{
		ft_printf("nbr = %d\n", i->nbr);
		ft_printf("lis = %d\n", i->lis);
		ft_printf("index %u\n", i->index);
		ft_printf("move_cost %u\n", i->move_cost);
		ft_printf("meridian %d\n", i->before_meridian);
		ft_printf("traget->nbr %d\n\n", i->target->nbr);
		i = i->next;
	}
}

static void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int		nbr_len;

	nbr_len = ft_lstsize(*stack_a);
	if (nbr_len == 2)
		ft_swap(stack_a, stack_b, SA);
	else if (nbr_len == 3)
		ft_sort_3(stack_a, stack_b);
	else if (nbr_len == 4 || nbr_len == 5)
		ft_sort_4_5(stack_a, stack_b);
	else
		ft_algorithm(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
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
