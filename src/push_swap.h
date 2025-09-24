/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:29:09 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/24 14:36:06 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	bool			flag;

	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				error(char *str);
int					c_len(char **array);
void				free_stack(t_stack **head);
int					is_in_order(t_stack **head);
int					nbr_check(char *argv);
int					dup_check(char **argv);
int					duplicates_check(char **argv);
void				input_check(int argc, char **argv);
void				k_sort(t_stack **a, t_stack **b, int len);
int					find_max_index_pos(t_stack *stack);
void				bring_to_top(t_stack **stack, int target_pos);
void				reintegrate_all(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
int					*array_copy(t_stack *a);
void				bu_sort(int *arr, int len);
int					*sort_arr(t_stack *a);
int					stack_len(t_stack *a);
int					main(int argc, char **argv);
t_stack				*get_last(t_stack *a);
t_stack				*get_min(t_stack *a);
t_stack				*get_max(t_stack *a);

#endif