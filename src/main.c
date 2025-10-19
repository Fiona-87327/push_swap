/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:49:44 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/19 18:32:42 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	input_check(argc, argv);
	a = init_stack_from_args(argc, argv);
	if (!a)
		return (1);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
	{
		free_stack(a);
		return (1);
	}
	b->top = NULL;
	b->size = 0;
	assign_index(a);
	k_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
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
