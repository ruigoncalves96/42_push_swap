/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:27:16 by randrade          #+#    #+#             */
/*   Updated: 2024/11/28 14:03:40 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_error_free_exit(t_list **lst)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(lst);
	exit(1);
}
