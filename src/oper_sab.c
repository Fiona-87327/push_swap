/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_sab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:53:24 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 18:39:10 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top_pair(t_stack **s)
{
	t_node	*first;
	t_node	*second;
	int		tmp_index;
	int		tmp_value;

	if (!s || !*s || !(*s)->top || !(*s)->top->next)
		return ;
	first = (*s)->top;
	second = first->next;
	tmp_index = first->index;
	tmp_value = first->value;
	first->index = second->index;
	first->value = second->value;
	second->index = tmp_index;
	second->value = tmp_value;
}

void	sa(t_stack **a)
{
	swap_top_pair(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_top_pair(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_top_pair(a);
	swap_top_pair(b);
	write(1, "ss\n", 3);
}
