/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:37:24 by randrade          #+#    #+#             */
/*   Updated: 2024/11/09 19:27:25 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_convert_and_parse(char **arg, t_list **stack_a)
{
	int	nbr;

	nbr = 0;
	while (*arg)
	{
		nbr = ft_atoi(*arg);
		if (nbr != 0 || **arg == '0')
			ft_lstadd_last(stack_a, ft_lstnew(nbr));
		else
		{
			ft_printf("ERROR\n");
			ft_lstclear(stack_a);
			exit(1);
		}
		arg++;
	}
}
