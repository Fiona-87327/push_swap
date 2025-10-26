/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 09:05:04 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/26 09:06:15 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (!a || a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(&a);
		return ;
	}
	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(&a);
	else if (top > mid && mid > bot)
		(sa(&a), rra(&a));
	else if (top > mid && top > bot)
		ra(&a);
	else if (top < mid && mid > bot && top < bot)
		(sa(&a), ra(&a));
	else if (top < mid && mid > bot)
		rra(&a);
}

void	four_five_sort(t_stack *a, t_stack *b)
{
	int	position;

	if (!a)
		return ;
	while (a->size > 3)
	{
		position = find_min_index_position(a);
		if (position <= a->size / 2)
			while (position-- > 0)
				ra(&a);
		else
			while (position++ < a->size)
				rra(&a);
		pb(&a, &b);
	}
	three_sort(a);
	while (!is_empty(b))
		pa(&a, &b);
}
