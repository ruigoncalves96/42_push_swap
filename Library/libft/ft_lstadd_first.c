/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruigoncalves <ruigoncalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:21:44 by randrade          #+#    #+#             */
/*   Updated: 2024/11/09 17:53:30 by ruigoncalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_firs(t_list **lst, t_list *new)
{
	t_list	*first;

	first = *lst;
	if (lst && new)
	{
		new->next = first;
		first->previous = new;
		first = new;
	}
}

/*
----- Parameters -----

	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be added to the list.

----- Return Value -----

	None.

----- External functs -----

	None.

----- Description -----

	Adds the node ’new’ at the beginning of the list.

*/
