/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyan@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:29:34 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/16 20:59:14 by jiyawang         ###   ########.fr       */
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

int	nbr_check(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	input_check(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**ar_tmp;

	i = 0;
	if (argc == 2)
		ar_tmp = ft_split(argv[1], ' ');
	else
		ar_tmp = argv + 1;
	while (ar_tmp[i])
	{
		tmp = ft_atoi(ar_tmp[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			error("Error: Number out of int range");
		if (duplicates_check(ar_tmp))
			error("Error: Duplicate numbers detected");
		if (!nbr_check(ar_tmp[i]))
			error("Error: Invalid number format");
		i++;
	}
	if (argc == 2)
		free(ar_tmp);
}
