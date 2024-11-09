/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruigoncalves <ruigoncalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:24:53 by randrade          #+#    #+#             */
/*   Updated: 2024/11/09 18:35:42 by ruigoncalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(*lst));
	if (lst == NULL)
		return (NULL);
	lst->nbr = content;
	lst->previous = NULL;
	lst->next = NULL;
	return (lst);
}

/*
----- Parameters -----

	content: The content to create the node with.

----- Return Value -----

	The new node.

----- External functs -----

	malloc.

----- Description -----

	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with
the value of the parameter ’content’.
	The variable ’next’ is initialized to NULL.

*/
