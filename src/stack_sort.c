/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:26:38 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/16 21:03:27 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	k_sort(t_stack **a, t_stack **b, int len)
{
	int	chunk;
	int	thresh;
	int	moved;

	if (len <= 3)
	{
		sort_three(a);
		return ;
	}
	chunk = len / 5 + 1;
	thresh = 0;
	moved = 0;
	while (*a && moved < len)
	{
		if ((*a)->index <= thresh + chunk)
		{
			pb(a, b);
			if (*b && (*b)->index <= thresh)
				rb(b);
			moved++;
		}
		else
			ra(a);
		if (stack_len(*b) >= chunk)
			thresh += chunk;
	}
	reintegrate_all(a, b);
}

int	find_max_index_pos(t_stack *stack)
{
	int		pos;
	int		max_pos;
	int		max_index;
	t_stack	*cur;

	pos = 0;
	max_pos = 0;
	if (!stack)
		return (-1);
	cur = stack;
	max_index = cur->index;
	while (cur)
	{
		if (cur->index > max_index)
		{
			max_index = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

void	bring_to_top(t_stack **stack, int target_pos)
{
	int	len;
	int	i;

	if (!stack || !*stack || target_pos < 0)
		return ;
	len = stack_len(*stack);
	if (target_pos <= len / 2)
	{
		i = 0;
		while (i++ < target_pos)
			rb(stack);
	}
	else
	{
		i = 0;
		while (i++ < len - target_pos)
			rrb(stack);
	}
}

void	reintegrate_all(t_stack **a, t_stack **b)
{
	int	max_pos;

	while (*b)
	{
		max_pos = find_max_index_pos(*b);
		if (max_pos >= 0)
			bring_to_top(b, max_pos);
		pa(a, b);
	}
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}
