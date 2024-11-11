/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:27:57 by randrade          #+#    #+#             */
/*   Updated: 2024/11/11 17:51:37 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Library/libft/libft.h"
# include "../Library/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

//	ERROR_HANDLING
void	ft_error_exit(void);
void	ft_error_free_exit(t_list **lst);

void	ft_convert_and_parse(char **arg, t_list **stack_a);

#endif
