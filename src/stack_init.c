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

static void	process_args(t_stack *stack, char **args)
{
	t_node	*new;
	int		i;

	i = 0;
	while (args[i])
	{
		new = create_node(ft_atoi(args[i]));
		if (!new)
		{
			free_stack(stack);
			return ;
		}
		append_node(stack, new);
		i++;
	}
}

static t_stack	*init_from_array(char **args, int should_free)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	process_args(stack, args);
	if (should_free)
		free_split(args);
	if (!stack->top)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

t_stack	*init_stack_from_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			if (args)
				free_split(args);
			return (NULL);
		}
		return (init_from_array(args, 1));
	}
	else
		return (init_from_array(argv + 1, 0));
}
