/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:29:09 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/25 13:16:46 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/* Stack Operations */
void				sa(t_stack **a);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/* Input Validation */
int					is_sign(char c);
int					is_digit(char c);
void				error(char *str);
int					argv_len(char **array);
int					nbr_check(char *argv);
int					is_empty(t_stack *stack);
int					duplicates_check(char **argv);
void				input_check(int argc, char **argv);
void				free_split(char **array);

/* Stack Initialization */
t_stack				*init_stack_from_args(int argc, char **argv);

/* Sorting Algorithms */
void				k_distribution_sort(t_stack *a, t_stack *b);
void				reintegration_sort(t_stack *a, t_stack *b);
void				four_five_sort(t_stack *a, t_stack *b);
void				three_sort(t_stack *a);
void				k_sort(t_stack *a, t_stack *b);

/* Utility Functions */
void				free_stack(t_stack *stack);
int					find_max_index(t_stack *stack);
int					find_min_index_position(t_stack *a);
int					position_of_index(t_stack *stack, int index);
void				assign_index(t_stack *stack);
int					is_sorted(t_stack *stack);

#endif