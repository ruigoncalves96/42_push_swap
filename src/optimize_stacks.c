/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:22 by randrade          #+#    #+#             */
/*   Updated: 2024/11/30 00:01:53 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_pivot(t_list **stack_a, t_list *pivot,
		t_stack_info *stack_info, unsigned int perc)
{
	t_list			*temp;
	unsigned int	smaller_nbrs;
	unsigned int	bigger_nbrs;

	smaller_nbrs = 0;
	bigger_nbrs = 0;
	temp = *stack_a;
	while (temp)
	{
		if (pivot->nbr > temp->nbr)
			smaller_nbrs++;
		else if (pivot->nbr < temp->nbr)
			bigger_nbrs++;
		temp = temp->next;
	}
	if (smaller_nbrs == perc)
		stack_info->first_pivot = pivot->nbr;
	else if (bigger_nbrs == perc)
		stack_info->second_pivot = pivot->nbr;
}

static void	ft_calculate_pivot(t_list **stack_a, t_stack_info *stack_info,
		float percentage)
{
	t_list			*pivot;
	unsigned int	perc;

	perc = (float)stack_info->a_len * percentage;
	pivot = *stack_a;
	while (pivot)
	{
		ft_check_pivot(stack_a, pivot, stack_info, perc);
		pivot = pivot->next;
	}
}

static void	ft_long_stack(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info)
{
	unsigned int	size;

	size = stack_info->a_len;
	while (size)
	{
		if ((*stack_a)->nbr < stack_info->first_pivot)
			ft_rotate(stack_a, stack_b, stack_info, RA);
		else
			ft_push(stack_a, stack_b, stack_info, PB);
		if (*stack_b && (*stack_b)->nbr > stack_info->second_pivot)
			ft_rotate(stack_a, stack_b, stack_info, RB);
		size--;
	}
	while (stack_info->a_len > 2)
		ft_push(stack_a, stack_b, stack_info, PB);
}

static void	ft_average_stack(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info)
{
	unsigned int	size;
	unsigned int	lis_size;

	size = stack_info->a_len;
	ft_lis(stack_a, stack_info);
	lis_size = stack_info->lis_size;
	while (size)
	{
		if ((*stack_a)->is_lis == true && lis_size != 0)
		{
			ft_rotate(stack_a, stack_b, stack_info, RA);
			lis_size--;
		}
		else
		{
			ft_push(stack_a, stack_b, stack_info, PB);
			if ((*stack_b)->next && (*stack_b)->nbr > (*stack_b)->next->nbr
				&& (*stack_b)->nbr > stack_info->first_pivot)
				ft_rotate(stack_a, stack_b, stack_info, RB);
		}
		size--;
	}
}

void	ft_optimize_stacks(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info)
{
	if (stack_info->a_len >= 200)
	{
		ft_calculate_pivot(stack_a, stack_info, 0.30);
		ft_long_stack(stack_a, stack_b, stack_info);
	}
	else
	{
		ft_calculate_pivot(stack_a, stack_info, 0.50);
		ft_average_stack(stack_a, stack_b, stack_info);
	}
}
