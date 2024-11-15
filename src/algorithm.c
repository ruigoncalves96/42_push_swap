/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:22 by randrade          #+#    #+#             */
/*   Updated: 2024/11/15 17:20:43 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void	ft_algorithm(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	while (ft_is_sorted(*stack_a) == false)
	{
		last = ft_lstlast(*stack_a);
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			ft_swap(stack_a, stack_b, SA);
		else if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr > last->nbr )
			ft_rotate(stack_a, stack_b, RA);
		else if ((*stack_a)->nbr < last->nbr && (*stack_a)->nbr < (*stack_a)->next->nbr && last->nbr < (*stack_a)->next->nbr)
		{
			ft_reverse_rotate(stack_a, stack_b, RRA);
			ft_swap(stack_a, stack_b, SA);
		}
		else 
			ft_rotate(stack_a, stack_b, RA);
	}
}



/*		ORGANIZE BY MINIMUM NUMBER
void	ft_get_info(t_list_info *list_info, t_list **stack_a)
{
	t_list	*check;

	check = *stack_a;
	list_info->min_nbr = check->nbr;
	list_info->position = 1;
	list_info->size = 1;
	while (check)
	{
		check = check->next;
		list_info->size++;
		if (check && check->nbr < list_info->min_nbr)
		{
			list_info->min_nbr = check->nbr;
			list_info->position = list_info->size;
		}
	}
}

void	ft_algorithm(t_list **stack_a, t_list **stack_b)
{
	t_list_info	list_info;
	int	middle;

	middle = 0;
	while ((*stack_a)->next && ft_is_sorted(*stack_a) == false)
	{	
		ft_get_info(&list_info, stack_a);
		while ((*stack_a)->nbr != list_info.min_nbr)
		{
			middle = list_info.size / 2;
			if (list_info.position < middle)
				ft_rotate(stack_a, stack_b, RA);
			else
				ft_reverse_rotate(stack_a, stack_b, RRA);
		}
		ft_push(stack_a, stack_b, PB);
	}
	while (*stack_b)
		ft_push(stack_a, stack_b, PA);
}
*/

//	COUNT NUMBER SORTED
//unsigned int	ft_count_is_sorted(t_list *stack_a)
//{
//	t_list	*i;
//	unsigned int	count;
//
//	count = 0;
//	i = stack_a;
//	while (i->next && i->nbr < i->next->nbr)
//	{
//		i = i->next;
//		count++;
//	}
//	return (count);
//}
//
