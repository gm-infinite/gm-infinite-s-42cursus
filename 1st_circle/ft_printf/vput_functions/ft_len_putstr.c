/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:42:28 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/11/01 12:59:25 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_lenputstr(char *s, t_flags *flags, int len)
{
	int	i;

	if (s == NULL && len >= 6)
	{
		ft_lenputstr("(null)", flags, len);
	}
	else if (s != NULL && len > 0)
	{
		i = 0;
		while (s[i] && len > 0)
		{
			ft_vputchar(s[i], flags);
			i++;
			len--;
		}
	}
}
