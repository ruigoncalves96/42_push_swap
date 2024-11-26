/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:27:57 by randrade          #+#    #+#             */
/*   Updated: 2024/11/26 17:39:02 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Library/libft/libft.h"
# include "../Library/ft_printf/ft_printf.h"
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

void	ft_print_stack(t_list *stack);

//	ERROR_HANDLING
void			ft_error_exit(void);
void			ft_error_free_exit(t_list **lst);

//	MOVES	
void			ft_swap(t_list **stack_a, t_list **stack_b, int move);
void			ft_push(t_list **stack_a, t_list **stack_b, int move);
void			ft_rotate(t_list **stack_a, t_list **stack_b, int move);
void			ft_reverse_rotate(t_list **stack_a, t_list **stack_b, int move);

//	ALGORITHM_UTILS
t_list			*ft_get_smallest_node(t_list **stack);
t_list			*ft_get_biggest_node(t_list **stack);
unsigned int	ft_update_stack_index(t_list **stack);
void			ft_move_to_top(t_list **stack_a, t_list **stack_b,
					t_list *node, char c);
bool			ft_is_sorted(t_list *stack_a);

//	LIS
int	*ft_lis(t_list **stack);

void			ft_algorithm(t_list **stack_a, t_list **stack_b);
void			ft_convert_and_parse(char **arg, t_list **stack_a);

#endif
