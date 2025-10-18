/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:29:34 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 12:37:31 by jiyawang         ###   ########.fr       */
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

int	nbr_check(char *argv)
{
	int	i;

	if (!argv || !*argv)
		return (0);
	i = 0;
	if (is_sign(argv[i]))
		i++;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (!is_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
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
