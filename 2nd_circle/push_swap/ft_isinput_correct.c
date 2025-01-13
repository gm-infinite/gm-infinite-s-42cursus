/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinput_correct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:43:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/21 11:30:27 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_output(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
static void	isduplicate(int argc, char **argv)
{
	char	*number;
	int		i;

	while (argc > 0)
	{
		number = argv[argc];
		i = argc - 1;
		while (i > 0)
		{
			if (ft_strncmp(number, argv[i], 11) == 0)
				error_output();
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
		number = argv[argc];
		size = ft_strlen(number);
		i = 0;
		if (number[i] == '-')
			size--;
		if (size > 11)
			error_output();
		else if (size == 10)
		{
			if (number[0] == '-')
				i = ft_strncmp(number, "-2147483648", 11);
			else
				i = ft_strncmp(number, "2147483647", 10);
		}
		if (i > 0)
			error_output();
		argc--;
	}
}

static void	isalldigit(int argc, char **argv)
{
	char	*number;
	int		i;

	while (argc > 0)
	{
		number = argv[argc];
		i = 0;
		if (number[i] == '-')
			i++;
		while (number[i] != '\0')
		{
			if (!(ft_isdigit(number[i])))
				error_output();
			i++;
		}
		argc--;
	}
}

void	isinputcorrect(int argc, char **argv)
{
	if (argc < 1)
		exit(0) ;
	isalldigit(argc, argv);
	isallint(argc, argv);
	if (argc > 1)
		isduplicate(argc, argv);
}
