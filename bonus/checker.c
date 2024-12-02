/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:34:36 by randrade          #+#    #+#             */
/*   Updated: 2024/12/02 18:13:56 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static void	ft_move(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info, char *move)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		ft_swap(stack_a, stack_b, stack_info, SA);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		ft_swap(stack_a, stack_b, stack_info, SB);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ft_swap(stack_a, stack_b, stack_info, SS);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		ft_push(stack_a, stack_b, stack_info, PA);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		ft_push(stack_a, stack_b, stack_info, PB);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ft_rotate(stack_a, stack_b, stack_info, RA);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		ft_rotate(stack_a, stack_b, stack_info, RB);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		ft_rotate(stack_a, stack_b, stack_info, RR);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		ft_reverse_rotate(stack_a, stack_b, stack_info, RRA);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		ft_reverse_rotate(stack_a, stack_b, stack_info, RRB);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		ft_reverse_rotate(stack_a, stack_b, stack_info, RRR);
}

static void	ft_make_moves(t_list **stack_a, t_list **stack_b,
		t_stack_info *stack_info)
{
	char	*move;

	move = get_next_line(0);
	if (move)
		ft_move(stack_a, stack_b, stack_info, move);
	while (move)
	{
		free(move);
		move = get_next_line(0);
		if (move)
			ft_move(stack_a, stack_b, stack_info, move);
	}
}

int	main(int argc, char *argv[])
{
	t_stack_info	stack_info;
	t_list		*stack_a;
	t_list		*stack_b;

	(void)argv;
	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	ft_memset(&stack_info, 0, sizeof(t_stack_info));
	ft_parse_and_convert(argv + 1, &stack_a);
	if (!stack_a)
		return (1);
	ft_make_moves(&stack_a, &stack_b, &stack_info);
	if (ft_is_sorted(stack_a) == true)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}

//CHECK MAKEFILE TO USE SAME FILES
//SEND NULL MAKE_MOVES STACK_INFO && RM STACK_INFO
