/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:55:16 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 15:44:40 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_node	*prev;
	t_node	*curr;

	if (!a || !*a || (*a)->size < 2)
		return ;
	prev = NULL;
	curr = (*a)->top;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = (*a)->top;
	(*a)->top = curr;
	prev->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_node	*prev;
	t_node	*curr;

	if (!b || !*b || (*b)->size < 2)
		return ;
	prev = NULL;
	curr = (*b)->top;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = (*b)->top;
	(*b)->top = curr;
	prev->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
