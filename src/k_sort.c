/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:26:38 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 19:44:54 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	k_distribution_sort(t_stack *a, t_stack *b)
{
	int	n;
	int	delta;
	int	th;

	n = a->size;
	delta = n / 20 + 7;
	th = 0;
	while (!is_empty(a))
	{
		if (a->top->index <= th + delta)
		{
			pb(&a, &b);
			if (b->top && b->top->index <= th)
				rb(&b);
			th++;
		}
		else
			ra(&a);
	}
}

void	reintegration_sort(t_stack *a, t_stack *b)
{
	int	max_i;
	int	pos;

	while (!is_empty(b))
	{
		max_i = find_max_index(b);
		pos = position_of_index(b, max_i);
		if (pos <= b->size / 2)
		{
			while (b->top && b->top->index != max_i)
				rb(&b);
		}
		else
		{
			while (b->top && b->top->index != max_i)
				rrb(&b);
		}
		pa(&a, &b);
	}
}

void	three_sort(t_stack *a)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;

	if (a->size == 2 && a->top->index > a->top->next->index)
		return (sa(&a));
	if (a->size != 3)
		return ;
	n1 = a->top;
	n2 = n1->next;
	n3 = n2->next;
	if (n1->index > n2->index && n2->index < n3->index && n1->index < n3->index)
		sa(&a);
	else if (n1->index > n2->index && n1->index > n3->index
		&& n2->index > n3->index)
		return (sa(&a), rra(&a));
	else if (n1->index > n3->index)
		ra(&a);
	else if (n2->index > n1->index && n2->index > n3->index
		&& n1->index < n3->index)
		return (sa(&a), ra(&a));
	else if (n1->index < n2->index && n2->index > n3->index)
		rra(&a);
}

void	four_five_sort(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 3)
	{
		pos = find_min_index_pos(a);
		if (pos <= a->size / 2)
			while (pos--)
				ra(&a);
		else
			while (pos++ < a->size)
				rra(&a);
		pb(&a, &b);
	}
	three_sort(a);
	while (!is_empty(b))
		pa(&a, &b);
}

void	k_sort(t_stack *a, t_stack *b)
{
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
