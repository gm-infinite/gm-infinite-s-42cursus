/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deci_int_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:56:58 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/11/01 12:59:25 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_deciintsize(int value, t_flags *flags)
{
	int	len;

	len = 0;
	if (value == 0 && flags->dot_size == 0)
		return (0);
	if (value == 0)
		len++;
	while (value != 0)
	{
		len++;
		value = value / 10;
	}
	return (len);
}
