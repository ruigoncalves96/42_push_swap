/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruigoncalves <ruigoncalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:21:44 by randrade          #+#    #+#             */
/*   Updated: 2024/11/12 13:04:46 by ruigoncalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_first(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->previous = NULL;
		new->next = *lst;
		if (*lst)
			(*lst)->previous = new;
		*lst = new;
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
