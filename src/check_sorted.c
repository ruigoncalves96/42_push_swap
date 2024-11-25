/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:41:09 by randrade          #+#    #+#             */
/*   Updated: 2024/11/25 17:22:17 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_list *stack_a)
{
	t_list	*i;

	i = stack_a->next;
	while (i)
	{
		if (i->nbr < i->previous->nbr)
			return (false);
		if (i->next && i->nbr > i->next->nbr)
			return (false);
		if (i->next && i->next->next)
			i = i->next->next;
		else
			break ;
	}
	return (true);
}
