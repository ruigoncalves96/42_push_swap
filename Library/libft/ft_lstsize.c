/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruigoncalves <ruigoncalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:49:36 by randrade          #+#    #+#             */
/*   Updated: 2024/11/09 18:36:27 by ruigoncalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

/*
----- Parameters -----

	lst: The beginning of the list.

----- Return Value -----

	The length of the list.

----- External functs -----

	None.

----- Description -----

	Counts the number of nodes in a list.

*/
