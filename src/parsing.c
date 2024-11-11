/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:37:24 by randrade          #+#    #+#             */
/*   Updated: 2024/11/11 17:51:13 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static long	ft_push_atoi(char **str)
{
	long	value;
	int	pos_neg;

	if (!str)
		return (0);
	value = 0;
	pos_neg = 1;
	while (**str == ' ' || **str == '\t' || **str == '\f'
		|| **str == '\r' || **str == '\n' || **str == '\v')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			pos_neg *= -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		value = (value * 10) + **str - 48;
		(*str)++;
	}
	value *= pos_neg;
	return (value);
}

static bool	ft_check_duplicate(t_list **stack_a)
{
	t_list	*i;
	t_list	*lst;

	lst = *stack_a;
	while (lst)
	{
		i = lst->next;
		while (i)
		{
			if (i->nbr == lst->nbr)
				return (false);
			i = i->next;
		}
		lst = lst->next;
	}
	return (true);
}

static bool	ft_check_content(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n'
				|| str[i] == '\v')
			i++;
		else if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] == '+' || str[i + 1] == '-')
				return (false);
			i++;
		}
		else
			return (false);
	}
	return (true);
}

void	ft_convert_and_parse(char **arg, t_list **stack_a)
{
	long	nbr;

	nbr = 0;
	while (*arg)
	{
		if (ft_check_content(*arg) == false)
				ft_error_free_exit(stack_a);
		while (**arg)
		{
			nbr = ft_push_atoi(arg);
			if (nbr < -2147483648 || nbr > 2147483647)
				ft_error_free_exit(stack_a);
			ft_lstadd_last(stack_a, ft_lstnew(nbr));
		}
		arg++;
	}
	if (ft_check_duplicate(stack_a) == false)
		ft_error_free_exit(stack_a);
}
