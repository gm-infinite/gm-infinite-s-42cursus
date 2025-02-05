/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:14:02 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/05 16:29:19 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

static void	error_output(void)
{
	printf("[USAGE] ./philosophers number_of_philosophers time_to_die time_to_eat \
time_to_sleep [must_eat_number] \
\n*all of the variables need to be positive integers*");
	exit(1);
}

static void	isallint(int argc, char **argv)
{
	char	*number;
	int		size;
	int		i;

	while (argc > 1)
	{
		number = argv[argc - 1];
		size = ft_strlen(number);
		i = 0;
		if (number[i] == '-')
			error_output();
		if (size >= 11)
			error_output();
		else if (size == 10)
			i = ft_strncmp(number, "2147483647", 10);
		if (i > 0)
			error_output();
		if (ft_atoi(number) == 0)
			error_output();
		argc--;
	}
}

static void	isalldigit(int argc, char **argv)
{
	char	*number;
	int		i;

	while (argc > 1)
	{
		number = argv[argc - 1];
		i = 0;
		if (number[i] == '-')
			error_output();
		while (number[i] != '\0')
		{
			if (!(ft_isdigit(number[i])))
				error_output();
			i++;
		}
		argc--;
	}
}

static void	isanynull(int argc, char **argv)
{
	int		i;
	int		j;
	char	*v;

	i = 0;
	while (argc > i)
	{
		if (argv[i] == NULL)
			error_output();
		j = 0;
		v = ft_strtrim(argv[i], " ");
		if (v[0] == '\0')
		{
			free(v);
			error_output();
		}
		free(v);
		i++;
	}
}

void	error_check(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		error_output();
	isanynull(argc, argv);
	isalldigit(argc, argv);
	isallint(argc, argv);
}
