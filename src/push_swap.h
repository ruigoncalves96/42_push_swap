/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:27:57 by randrade          #+#    #+#             */
/*   Updated: 2024/11/30 01:11:51 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Library/libft/libft.h"
# include "../Library/ft_printf/ft_printf.h"
# include "../Library/get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_stack_info
{
	unsigned int	a_len;
	unsigned int	b_len;
	unsigned int	lis_size;
	int				first_pivot;
	int				second_pivot;
}		t_stack_info;

//	ERROR_HANDLING
void			ft_error_exit(void);
void			ft_error_free_exit(t_list **lst);

//	MOVES	
void			ft_swap(t_list **stack_a, t_list **stack_b,
					t_stack_info *stack_info, int move);
void			ft_push(t_list **stack_a, t_list **stack_b,
					t_stack_info *stack_info, int move);
void			ft_rotate(t_list **stack_a, t_list **stack_b,
					t_stack_info *stack_info, int move);
void			ft_reverse_rotate(t_list **stack_a, t_list **stack_b,
					t_stack_info *stack_info, int move);

//	ALGORITHM_UTILS
t_list			*ft_get_smallest_node(t_list **stack);
t_list			*ft_get_biggest_node(t_list **stack);
unsigned int	ft_update_stack_index(t_list **stack);
void			ft_move_to_top(t_list **stack, t_list *node,
					t_stack_info *stack_info, char c);
bool			ft_is_sorted(t_list *stack_a);

//	MOVE_ALGORITHM
void			ft_move_algorithm(t_list **stack_a, t_list **stack_b,
					t_stack_info *stack_info);

//	OPTIMIZE_STACKS
void			ft_optimize_stacks(t_list **stack_a, t_list **stack_b,
					t_stack_info *stack_info);

//	LIS
t_list			*ft_get_biggest_lis(t_list **stack);
void			ft_lis(t_list **stack, t_stack_info *stack_info);

//	ALGORITHM
void			ft_sort_3(t_list **stack_a, t_list **stack_b,
					t_stack_info *stack_info);
void			ft_sort_4_5(t_list **stack_a, t_list **stack_b,
					t_stack_info *stack_info);
void			ft_algorithm(t_list **stack_a, t_list **stack_b,
					t_stack_info *stack_info);

void			ft_convert_and_parse(char **arg, t_list **stack_a);

#endif
