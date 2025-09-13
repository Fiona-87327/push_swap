/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:24:31 by jiyan             #+#    #+#             */
/*   Updated: 2025/09/12 20:47:41 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				error(char *str);
int					c_len(char **array);
void				free_stack(t_stack **head);
int					is_in_order(t_stack **head);
int					nbr_check(char *argv);
int					duplicates_check(char **argv);
void				input_check(int argc, char **argv);

#endif