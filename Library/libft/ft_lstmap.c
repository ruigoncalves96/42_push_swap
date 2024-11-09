/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruigoncalves <ruigoncalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 01:03:49 by randrade          #+#    #+#             */
/*   Updated: 2024/11/09 18:41:51 by ruigoncalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*map;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	map = NULL;
	while (lst)
	{
		if (f)
			new_node = ft_lstnew(f(lst->nbr));
		else
			new_node = ft_lstnew(lst->nbr);
		if (new_node == NULL)
		{
			ft_lstclear(&map);
			return (NULL);
		}
		ft_lstadd_last(&map, new_node);
		lst = lst->next;
	}
	return (map);
}

/*
----- Parameters -----

	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on the list.
	del: The address of the function used to delete the content of
a node if needed.

----- Return Value -----

	The new list.
	NULL if the allocation fails.

----- External functs -----

	malloc, free.

----- Description -----

	Iterates the list ’lst’ and applies the function ’f’ on the content 
of each node. 
	Creates a new list resulting of the successive applications of
the function ’f’. 
	The ’del’ function is used to delete the content of a node if needed.

*/
