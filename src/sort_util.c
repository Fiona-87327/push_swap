/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:30:22 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/26 09:25:48 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	find_max_index(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	if (!stack || !stack->top)
		return (-1);
	tmp = stack->top;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	position_of_index(t_stack *stack, int index)
{
	t_node	*tmp;
	int		position;

	if (!stack || !stack->top)
		return (-1);
	tmp = stack->top;
	position = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (-1);
}

int	find_min_index_position(t_stack *a)
{
	t_node	*tmp;
	int		min;
	int		position;
	int		i;

	tmp = a->top;
	min = tmp->index;
	position = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			position = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (position);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
