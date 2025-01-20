/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_argv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:42 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:51:58 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_substr(char const *s, char c)
{
	int	count;
	int	at_deliminar;

	count = 0;
	at_deliminar = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!at_deliminar)
			{
				at_deliminar = 1;
				count++;
			}
		}
		else
			at_deliminar = 0;
		s++;
	}
	return (count);
}

char	**ft_normalize_argv(int argc, char **argv, int *wc)
{
	char	**ret;
	char	*joiner;
	char	*temp;
	int		i;

	if (argc > 1)
		joiner = ft_strdup(argv[1]);
	i = 2;
	temp = NULL;
	while (argc > i)
	{
		temp = joiner;
		joiner = ft_strjoin(temp, " ");
		free(temp);
		temp = joiner;
		joiner = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
	}
	*wc = ft_count_substr(joiner, ' ');
	ret = ft_split(joiner, ' ');
	return (free(joiner), ret);
}
