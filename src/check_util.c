/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:29:34 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 16:47:48 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	c_len(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

void	free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
