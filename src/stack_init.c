/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:00:00 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 16:41:50 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

static void	append_node(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack->top)
		stack->top = new;
	else
	{
		last = stack->top;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	stack->size++;
}

t_stack	*init_stack_from_args(int argc, char **argv)
{
	t_stack	*stack;
	t_node	*new;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	i = 1;
	while (i < argc)
	{
		new = create_node(ft_atoi(argv[i]));
		if (!new)
			return (NULL);
		append_node(stack, new);
		i++;
	}
	return (stack);
}
