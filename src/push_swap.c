/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:30 by randrade          #+#    #+#             */
/*   Updated: 2024/11/09 19:30:17 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*i;

	(void)argc;
	(void)argv;
	stack_a = NULL;
	ft_convert_and_parse(argv + 1, &stack_a);
	i = stack_a;
	while (i)
	{
		ft_printf("%d\n", i->nbr);
		i = i->next;
	}
	ft_lstclear(&stack_a);
	return (0);
}
