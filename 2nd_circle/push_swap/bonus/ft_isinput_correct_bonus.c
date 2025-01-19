/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinput_correct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:43:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/14 18:01:17 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	error_output(char **argv)
{
	int i;

	i = 0;
	write(2, "Error\n", 6);
	while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
	free(argv);
	exit(1);
}

static void	isduplicate(int argc, char **argv)
{
	char	*number;
	int		i;

	while (argc > 0)
	{
		number = argv[argc - 1];
		i = argc - 2;
		while (i >= 0)
		{
			if (ft_strncmp(number, argv[i], 11) == 0)
				error_output(argv);
			i--;
		}
		argc--;
	}
}

static void	isallint(int argc, char **argv)
{
	char	*number;
	int		size;
	int		i;

	while (argc > 0)
	{
		number = argv[argc - 1];
		size = ft_strlen(number);
		i = 0;
		if (number[i] == '-')
			size--;
		if (size > 11)
			error_output(argv);
		else if (size == 10)
		{
			if (number[0] == '-')
				i = ft_strncmp(number, "-2147483648", 11);
			else
				i = ft_strncmp(number, "2147483647", 10);
		}
		if (i > 0)
			error_output(argv);
		argc--;
	}
}

static void	isalldigit(int argc, char **argv)
{
	char	*number;
	int		i;

	while (argc > 0)
	{
		number = argv[argc - 1];
		i = 0;
		if (number[i] == '-')
			i++;
		while (number[i] != '\0')
		{
			if (!(ft_isdigit(number[i])))
				error_output(argv);
			i++;
		}
		argc--;
	}
}

static void isanynull(int argc, char **argv, char **normal_argv)
{
	int		i;

	i = 0;
	while (argc  > i)
	{
		if (argv[i] == NULL)
			error_output(normal_argv);
		if (argv[i][0] == '\0')
			error_output(normal_argv);
		i++;
	}
}

void	isinputcorrect(int argc, char **argv, char **normal_argv, int argc2)
{
	isanynull(argc2, argv, normal_argv);
	isalldigit(argc, normal_argv);
	isallint(argc, normal_argv);
	if (argc >= 2)
		isduplicate(argc, normal_argv);
}
