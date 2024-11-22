/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:30 by randrade          #+#    #+#             */
/*   Updated: 2024/11/22 17:40:49 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	//	CHECK FT_SPLIT if works well
	ft_convert_and_parse(argv + 1, &stack_a);
//	ft_print_stack(stack_a);
	ft_algorithm(&stack_a, &stack_b);
//	ft_printf("UPDATE A\n");
//	ft_print_stack(stack_a);
//	ft_printf("UPDATE B\n");
//	ft_print_stack(stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
