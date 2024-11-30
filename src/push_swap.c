/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:30 by randrade          #+#    #+#             */
/*   Updated: 2024/11/29 23:59:28 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ft_print_stack_a(t_list *stack)
//{
//	t_list	*i;
//
//	i = stack;
//	while (i)
//	{
//		ft_printf("nbr = %d\n", i->nbr);
//		ft_printf("index %u\n", i->index);
//		ft_printf("meridian %d\n\n", i->before_meridian);
//		ft_printf("is_lis %d\n\n", i->is_lis);
//		i = i->next;
//	}
//}
//
//void	ft_print_stack_b(t_list *stack)
//{
//	t_list	*i;
//
//	i = stack;
//	while (i)
//	{
//		ft_printf("nbr = %d\n", i->nbr);
//		ft_printf("lis = %d\n", i->lis);
//		ft_printf("index %u\n", i->index);
//		ft_printf("move_cost %u\n", i->move_cost);
//		ft_printf("meridian %d\n", i->before_meridian);
//		ft_printf("traget->nbr %d\n\n", i->target->nbr);
//		i = i->next;
//	}
//}

static void	ft_sort(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info)
{
	stack_info->a_len = ft_update_stack_index(stack_a);
	stack_info->b_len = ft_update_stack_index(stack_b);
	if (stack_info->a_len == 2)
		ft_swap(stack_a, stack_b, stack_info, SA);
	else if (stack_info->a_len == 3)
		ft_sort_3(stack_a, stack_b, stack_info);
	else if (stack_info->a_len == 4 || stack_info->a_len == 5)
		ft_sort_4_5(stack_a, stack_b, stack_info);
	else
		ft_algorithm(stack_a, stack_b, stack_info);
}

int	main(int argc, char *argv[])
{
	t_stack_info	stack_info;
	t_list			*stack_a;
	t_list			*stack_b;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	ft_memset(&stack_info, 0, sizeof(t_stack_info));
	ft_convert_and_parse(argv + 1, &stack_a);
	if (ft_is_sorted(stack_a) == false)
		ft_sort(&stack_a, &stack_b, &stack_info);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
