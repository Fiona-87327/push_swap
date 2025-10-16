/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:26:38 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/24 15:09:37 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  K_sort(t_stack **a, t_stack **b)
{
	int	n;
	int chunk_size;
	int current_limit;

	n = a->size;
	delta = n / 20 + 7;
	threshold = 0;
	while (!is_empty(a))
	{
		if (a->top->index <= threshold + delta)
		{
			push(a, b);
			if (b->top->index <= threshold)
				rotate(b);
			threshold++;
		}
		else
			rotate(a);
	}
}
