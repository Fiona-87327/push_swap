/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:29:49 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/16 21:02:18 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->flag = false;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	add_to_stack(t_stack **head, t_stack *new_node)
{
	t_stack	*cur;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
}

void	set_indices(t_stack **head)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		idx;

	cur = *head;
	while (cur)
	{
		idx = 0;
		cmp = *head;
		while (cmp)
		{
			if (cmp->value < cur->value)
				idx++;
			cmp = cmp->next;
		}
		cur->index = idx;
		cur = cur->next;
	}
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*head;
	char	**numbers;
	int		i;
	int		val;

	head = NULL;
	i = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	while (numbers[i])
	{
		val = ft_atoi(numbers[i]);
		add_to_stack(&head, create_node(val, 0));
		i++;
	}
	if (argc == 2)
	{
		i = 0;
		while (numbers[i])
			free(numbers[i++]);
		free(numbers);
	}
	set_indices(&head);
	return (head);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	if (argc < 2)
		return (0);
	input_check(argc, argv);
	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	if (is_in_order(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	len = stack_len(stack_a);
	k_sort(&stack_a, &stack_b, len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
