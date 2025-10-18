/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swapo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:53:24 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 15:44:44 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (!a || !*a || (*a)->size < 2)
		return ;
	tmp = (*a)->top->value;
	(*a)->top->value = (*a)->top->next->value;
	(*a)->top->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	t_node	*first;
	t_node	*second;
	int		tmp_index;
	int		tmp_value;

	if (!b || !*b || !(*b)->top || !(*b)->top->next)
		return ;
	first = (*b)->top;
	second = first->next;
	tmp_index = first->index;
	tmp_value = first->value;
	first->index = second->index;
	first->value = second->value;
	second->index = tmp_index;
	second->value = tmp_value;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	t_node	*first;
	t_node	*second;
	int		tmp_index;
	int		tmp_value;

	if (a && *a && (*a)->top && (*a)->top->next)
	{
		first = (*a)->top;
		second = first->next;
		tmp_index = first->index;
		tmp_value = first->value;
		first->index = second->index;
		first->value = second->value;
		second->index = tmp_index;
		second->value = tmp_value;
	}
	if (b && *b && (*b)->top && (*b)->top->next)
	{
		first = (*b)->top;
		second = first->next;
		tmp_index = first->index;
		tmp_value = first->value;
		first->index = second->index;
		first->value = second->value;
		second->index = tmp_index;
		second->value = tmp_value;
	}
	write(1, "ss\n", 3);
}

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
