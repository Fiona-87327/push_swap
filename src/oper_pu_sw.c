/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_pu_sw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:53:24 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/24 13:32:02 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp_index;
	int	tmp_value;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp_index = (*a)->index;
	tmp_value = (*a)->value;
	(*a)->index = (*a)->next->index;
	(*a)->value = (*a)->next->value;
	(*a)->next->index = tmp_index;
	(*a)->next->value = tmp_value;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	tmp_index;
	int	tmp_value;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp_index = (*b)->index;
	tmp_value = (*b)->value;
	(*b)->index = (*b)->next->index;
	(*b)->value = (*b)->next->value;
	(*b)->next->index = tmp_index;
	(*b)->next->value = tmp_value;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int	tmp_index_a;
	int	tmp_value_a;
	int	tmp_index_b;
	int	tmp_value_b;

	if (a && *a && (*a)->next)
	{
		tmp_index_a = (*a)->index;
		tmp_value_a = (*a)->value;
		(*a)->index = (*a)->next->index;
		(*a)->value = (*a)->next->value;
		(*a)->next->index = tmp_index_a;
		(*a)->next->value = tmp_value_a;
	}
	if (b && *b && (*b)->next)
	{
		tmp_index_b = (*b)->index;
		tmp_value_b = (*b)->value;
		(*b)->index = (*b)->next->index;
		(*b)->value = (*b)->next->value;
		(*b)->next->index = tmp_index_b;
		(*b)->next->value = tmp_value_b;
	}
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}
