/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:29:49 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 16:06:31 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_long_strict(const char *s, long long *out)
{
	int			sign;
	long long	res;

	if (!s || !*s)
		return (0);
	sign = 1;
	if (is_sign(*s))
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (0);
	res = 0;
	while (*s)
	{
		if (!is_digit(*s))
			return (0);
		res = res * 10 + (*s - '0');
		s++;
	}
	res *= sign;
	*out = res;
	return (1);
}

static void	validate_number(char *str)
{
	long long	val;

	if (!nbr_check(str))
		error("Error");
	if (!parse_long_strict(str, &val) || val < INT_MIN || val > INT_MAX)
		error("Error");
}

static char	**prepare_args(int argc, char **argv)
{
	char	**ar_tmp;

	if (argc == 2)
		ar_tmp = ft_split(argv[1], ' ');
	else
		ar_tmp = argv + 1;
	if (!ar_tmp || !ar_tmp[0])
	{
		if (argc == 2)
			free_split(ar_tmp);
		error("Error");
	}
	return (ar_tmp);
}

void	input_check(int argc, char **argv)
{
	int		i;
	char	**ar_tmp;

	if (argc < 2)
		return ;
	ar_tmp = prepare_args(argc, argv);
	i = 0;
	while (ar_tmp[i])
	{
		validate_number(ar_tmp[i]);
		i++;
	}
	if (duplicates_check(ar_tmp))
	{
		if (argc == 2)
			free_split(ar_tmp);
		error("Error");
	}
	if (argc == 2)
		free_split(ar_tmp);
}
