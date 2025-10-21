/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:30:22 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/19 18:33:58 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int		len;
	t_node	*node;

	if (!a)
		return (0);
	len = 0;
	node = a->top;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

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
	int		pos;

	if (!stack || !stack->top)
		return (-1);
	tmp = stack->top;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		pos++;
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
