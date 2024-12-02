/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruigoncalves <ruigoncalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:37:24 by randrade          #+#    #+#             */
/*   Updated: 2024/12/02 16:59:14 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

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
			if (str[i + 1] == '+' || str[i + 1] == '-'
				|| str[i + 1] < 48 || str[i + 1] > 57)
				return (false);
			i++;
		}
		else
			return (false);
	}
	return (true);
}

static void	ft_convert_to_stack(char **array, t_list **stack_a)
{
	int	nbr;

	while (*array)
	{
		nbr = 0;
		if (ft_push_atoi(*array, &nbr) == false)
			ft_error_free_exit(array, stack_a);
		ft_lstadd_last(stack_a, ft_lstnew(nbr));
		array++;
	}
}

static bool	ft_has_duplicates(t_list **stack_a)
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
				return (true);
			i = i->next;
		}
		lst = lst->next;
	}
	return (false);
}

void	ft_parse_and_convert(char **arg, t_list **stack_a)
{
	char	**array;

	while (*arg)
	{
		if (*arg[0] != '\0')
		{
			if (ft_check_content(*arg) == false)
				ft_error_free_exit(NULL, stack_a);
			array = ft_split(*arg, ' ');
			if (!array)
				ft_error_free_exit(NULL, stack_a);
			ft_convert_to_stack(array, stack_a);
			ft_free_array(array);
		}
		arg++;
	}
	if (ft_has_duplicates(stack_a) == true)
		ft_error_free_exit(NULL, stack_a);
}
