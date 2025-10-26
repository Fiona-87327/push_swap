/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:49:44 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/26 09:09:44 by jiyawang         ###   ########.fr       */
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
