/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:34:36 by randrade          #+#    #+#             */
/*   Updated: 2024/12/03 16:53:07 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static bool	ft_move(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		ft_swap(stack_a, stack_b, NULL, SA);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		ft_swap(stack_a, stack_b, NULL, SB);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ft_swap(stack_a, stack_b, NULL, SS);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		ft_push(stack_a, stack_b, NULL, PA);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		ft_push(stack_a, stack_b, NULL, PB);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ft_rotate(stack_a, stack_b, NULL, RA);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		ft_rotate(stack_a, stack_b, NULL, RB);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		ft_rotate(stack_a, stack_b, NULL, RR);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		ft_reverse_rotate(stack_a, stack_b, NULL, RRA);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		ft_reverse_rotate(stack_a, stack_b, NULL, RRB);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		ft_reverse_rotate(stack_a, stack_b, NULL, RRR);
	else
		return (false);
	return (true);
}

static void	ft_check_move(t_list **stack_a, t_list **stack_b, char *move)
{
	if (move)
	{
		if (ft_move(stack_a, stack_b, move) == false)
		{
			ft_lstclear(stack_b);
			ft_error_free_exit(NULL, stack_a);
		}
	}
}

static void	ft_make_moves(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = get_next_line(0);
	ft_check_move(stack_a, stack_b, move);
	while (move)
	{
		free(move);
		move = get_next_line(0);
		ft_check_move(stack_a, stack_b, move);
	}
}

int	main(int argc, char *argv[])
{
	t_list			*stack_a;
	t_list			*stack_b;

	(void)argv;
	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	ft_parse_and_convert(argv + 1, &stack_a);
	if (!stack_a)
		return (1);
	ft_make_moves(&stack_a, &stack_b);
	if (ft_is_sorted(stack_a) == true && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
