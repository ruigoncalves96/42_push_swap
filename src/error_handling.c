/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:27:16 by randrade          #+#    #+#             */
/*   Updated: 2024/12/02 16:48:38 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_error_free_exit(char **array, t_list **lst)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_array(array);
	ft_lstclear(lst);
	exit(1);
}
