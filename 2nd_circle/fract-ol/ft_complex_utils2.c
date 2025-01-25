/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:08:24 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/25 15:49:29 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	div_complex(t_complex a, t_complex b)
{
	t_complex	ret;

	if ((b.x * b.x + b.y * b.y) == 0)
	{
		ret.x = INFINITY;
		ret.y = INFINITY;
	}
	else
	{
		ret.x = (a.x * b.x + a.y * b.y) / (b.x * b.x + b.y * b.y);
		ret.y = (a.y * b.x + a.x * b.y) / (b.x * b.x + b.y * b.y);
	}
	return (ret);
}

t_complex	mult_complex(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.x = a.x * b.x - a.y * b.y;
	ret.y = a.x * b.y + a.y * b.x;
	return (ret);
}

t_complex	abs_complex(t_complex a)
{
	t_complex	t;

	t.x = fabs(a.x);
	t.y = fabs(a.y);
	return (t);
}
