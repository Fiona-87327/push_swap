/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:54:05 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 17:44:23 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || (*a)->size < 2)
		return ;
	first = (*a)->top;
	last = (*a)->top;
	while (last->next)
		last = last->next;
	(*a)->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !*b || (*b)->size < 2)
		return ;
	first = (*b)->top;
	last = (*b)->top;
	while (last->next)
		last = last->next;
	(*b)->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}
