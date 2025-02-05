/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:14:02 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/03 16:09:38 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	error_output(int *i)
{
	printf("[USAGE] ./philosophers number_of_philosophers time_to_die time_to_eat \
time_to_sleep [must_eat_number] \
\n*all of the variables need to be positive integers*");
	*i = 1;
}

static void	isallint(int argc, char **argv, int *k)
{
	char	*number;
	int		size;
	int		i;

	while (argc > 1)
	{
		number = argv[argc - 1];
		size = ft_strlen(number);
		i = 0;
		if (size >= 11 && *k != 1)
			error_output(k);
		else if (size == 10)
			i = ft_strncmp(number, "2147483647", 10);
		if (i > 0 && *k != 1)
			error_output(k);
		if (ft_atoi(number) == 0 && *k != 1)
			error_output(k);
		argc--;
	}
}

static void	isalldigit(int argc, char **argv, int *k)
{
	char	*number;
	int		i;

	while (argc > 1)
	{
		number = argv[argc - 1];
		i = 0;
		if (number[i] == '-')
		{
			error_output(k);
			return ;
		}
		while (number[i] != '\0')
		{
			if (!(ft_isdigit(number[i])))
			{
				error_output(k);
				return ;
			}
			i++;
		}
		argc--;
	}
}

static void	isanynull(int argc, char **argv, int *k)
{
	int		i;
	int		j;
	char	*v;

	i = 0;
	while (argc > i)
	{
		if (argv[i] == NULL)
			error_output(k);
		j = 0;
		v = ft_strtrim(argv[i], " ");
		if (v[0] == '\0')
		{
			free(v);
			error_output(k);
			return ;
		}
		free(v);
		i++;
	}
}

int	error_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		error_output(&i);
	if (i != 1)
		isanynull(argc, argv, &i);
	if (i != 1)
		isalldigit(argc, argv, &i);
	if (i != 1)
		isallint(argc, argv, &i);
	return (i);
}
