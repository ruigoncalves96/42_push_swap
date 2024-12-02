/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruigoncalves <ruigoncalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:37:24 by randrade          #+#    #+#             */
/*   Updated: 2024/12/02 16:52:10 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_parse_atoi(char **str, int *pos_neg)
{
	while (**str == ' ' || **str == '\t' || **str == '\f'
		|| **str == '\r' || **str == '\n' || **str == '\v')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*pos_neg *= -1;
		(*str)++;
	}
}

bool	ft_push_atoi(char *str, int *nbr)
{
	long	value;
	int		pos_neg;

	if (!str)
		return (0);
	value = 0;
	pos_neg = 1;
	ft_parse_atoi(&str, &pos_neg);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			value = (value * 10) + *str - 48;
			if (value > 2147483648 || (value == 2147483648 && pos_neg == 1))
				return (false);
		}
		else
			return (false);
		str++;
	}
	value *= pos_neg;
	*nbr = value;
	return (true);
}
