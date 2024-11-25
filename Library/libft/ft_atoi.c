/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruigoncalves <ruigoncalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:23:26 by randrade          #+#    #+#             */
/*   Updated: 2024/11/25 17:05:08 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	value;
	int		i;
	int		pos_neg;

	if (!str)
		return (0);
	value = 0;
	i = 0;
	pos_neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			pos_neg *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		value = (value * 10) + str[i++] - 48;
	value *= pos_neg;
	if (value < -2147483648 || value > 2147483647)
		value = 0;
	return (value);
}
