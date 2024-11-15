/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:30 by randrade          #+#    #+#             */
/*   Updated: 2024/11/15 17:21:07 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_print_stack(t_list *stack)
{
	t_list	*i;

	i = stack;
	while (i)
	{
		ft_printf("%d\n", i->nbr);
		i = i->next;
	}
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
//	ft_print_stack(stack_a);
	ft_algorithm(&stack_a, &stack_b);
//	ft_print_stack(stack_a);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
