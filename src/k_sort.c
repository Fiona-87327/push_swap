/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:26:38 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/26 09:09:55 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	k_distribution_sort(t_stack *a, t_stack *b)
{
	int	delta;
	int	threshold;

	delta = a->size / 20 + 7;
	threshold = 0;
	while (!is_empty(a))
	{
		if (a->top->index <= threshold + delta)
		{
			pb(&a, &b);
			if (!is_empty(b) && b->top->index <= threshold)
				rb(&b);
			threshold++;
		}
		else
			ra(&a);
	}
}

void	reintegration_sort(t_stack *a, t_stack *b)
{
	int	max_index;
	int	position;

	if (!a)
		return ;
	while (!is_empty(b))
	{
		max_index = find_max_index(b);
		position = position_of_index(b, max_index);
		if (position <= b->size / 2)
		{
			while (!is_empty(b) && b->top->index != max_index)
				rb(&b);
		}
		else
		{
			while ((!is_empty(b)) && b->top->index != max_index)
				rrb(&b);
		}
		pa(&a, &b);
	}
}

void	k_sort(t_stack *a, t_stack *b)
{
	if (!a || is_sorted(a))
		return ;
	if (a->size <= 3)
		three_sort(a);
	else if (a->size <= 5)
		four_five_sort(a, b);
	else
	{
		k_distribution_sort(a, b);
		reintegration_sort(a, b);
	}
}

void	assign_index(t_stack *stack)
{
	t_node	*i_node;
	t_node	*j_node;
	int		index;

	i_node = stack->top;
	while (i_node)
	{
		index = 0;
		j_node = stack->top;
		while (j_node)
		{
			if (j_node->value < i_node->value)
				index++;
			j_node = j_node->next;
		}
		i_node->index = index;
		i_node = i_node->next;
	}
}
