/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:20:51 by jiyan             #+#    #+#             */
/*   Updated: 2025/09/12 21:01:46 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	dup_check(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = c_len(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
			error("error");
		if (duplicates_check(ar_tmp))
			error("error");
		if (!nbr_check(ar_tmp[i]))
			error("error");
		i++;
	}
	if (argc == 2)
		free(ar_tmp);
}
