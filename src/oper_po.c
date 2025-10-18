/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_po.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:36:46 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 18:37:31 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	if (!b || !*b || !(*b)->top)
		return ;
	tmp = (*b)->top;
	(*b)->top = tmp->next;
	(*b)->size--;
	tmp->next = (*a)->top;
	(*a)->top = tmp;
	(*a)->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	if (!a || !*a || !(*a)->top)
		return ;
	tmp = (*a)->top;
	(*a)->top = tmp->next;
	(*a)->size--;
	tmp->next = (*b)->top;
	(*b)->top = tmp;
	(*b)->size++;
	write(1, "pb\n", 3);
}
