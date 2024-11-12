/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:30 by randrade          #+#    #+#             */
/*   Updated: 2024/11/12 14:37:55 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	ft_print_stack(t_list *stack)
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

	if (argc < 2)
		return (1);
	stack_a = NULL;
	ft_convert_and_parse(argv + 1, &stack_a);
	ft_print_stack(stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
