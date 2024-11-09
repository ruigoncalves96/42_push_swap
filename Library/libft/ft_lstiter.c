/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruigoncalves <ruigoncalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:51:30 by randrade          #+#    #+#             */
/*   Updated: 2024/11/09 18:43:33 by ruigoncalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, int (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->nbr);
		lst = lst->next;
	}
}

/*
----- Parameters -----

	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on the list.

----- Return Value -----

	None.

----- External Functs -----

	None.

----- Description -----

	Iterates the list ’lst’ and applies the function ’f’ on the content
of each node.

*/
