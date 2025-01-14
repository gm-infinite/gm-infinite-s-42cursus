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

#include "push_swap.h"

static void	error_output(char **argv, int j)
{
	int i;

	i = 0;
	write(2, "Error\n", 6);
	if (j == 1)
	{
		while (argv[i] != NULL)
			{
				free(argv[i]);
				i++;
			}
		free(argv);
	}
	exit(1);
}
static void	isduplicate(int argc, char **argv, int j)
{
	char	*number;
	int		i;

	while (argc + j > 0)
	{
		number = argv[argc];
		i = argc - 1;
		while (i >= 0)
		{
			if (ft_strncmp(number, argv[i], 11) == 0)
				error_output(argv, j);
			i--;
		}
		argc--;
	}
}

static void	isallint(int argc, char **argv, int j)
{
	char	*number;
	int		size;
	int		i;

	while (argc + j > 0)
	{
		number = argv[argc];
		size = ft_strlen(number);
		i = 0;
		if (number[i] == '-')
			size--;
		if (size > 11)
			error_output(argv, j);
		else if (size == 10)
		{
			if (number[0] == '-')
				i = ft_strncmp(number, "-2147483648", 11);
			else
				i = ft_strncmp(number, "2147483647", 10);
		}
		if (i > 0)
			error_output(argv, j);
		argc--;
	}
}

static void	isalldigit(int argc, char **argv, int j)
{
	char	*number;
	int		i;

	while (argc + j > 0)
	{
		number = argv[argc];
		i = 0;
		if (number[i] == '-')
			i++;
		while (number[i] != '\0')
		{
			if (!(ft_isdigit(number[i])))
				error_output(argv, j);
			i++;
		}
		argc--;
	}
}

static void isanynull(int argc, char **argv, int j)
{
	int		i;

	i = !(j == 1);
	while (argc + j >= i)
	{
		if (argv[i] == NULL)
			error_output(argv, j);
		if (argv[i][0] == '\0')
			error_output(argv, j);
		i++;
	}
}

void	isinputcorrect(int argc, char **argv, int j)
{
	isanynull(argc, argv, j);
	if (argc + j < 1)
		exit(0);
	isalldigit(argc, argv, j);
	isallint(argc, argv, j);
	if (argc + j > 1)
		isduplicate(argc, argv, j);
}
