/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:27:16 by randrade          #+#    #+#             */
/*   Updated: 2024/12/01 01:07:07 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	ft_error_exit(void)
{
	exit(1);
}

void	ft_error_free_exit(t_list **lst)
{
	ft_lstclear(lst);
	exit(1);
}
