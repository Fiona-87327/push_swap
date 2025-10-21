/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:26:38 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/19 15:27:46 by jiyawang         ###   ########.fr       */
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
