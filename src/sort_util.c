/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:30:22 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/24 11:51:39 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

t_stack	*get_last(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_stack	*get_min(t_stack *a)
{
	t_stack	*min;

	if (!a)
		return (NULL);
	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

t_stack	*get_max(t_stack *a)
{
	t_stack	*max;

	if (!a)
		return (NULL);
	max = a;
	while (a)
	{
		if (a->value > max->value)
			max = a;
		a = a->next;
	}
	return (max);
}
