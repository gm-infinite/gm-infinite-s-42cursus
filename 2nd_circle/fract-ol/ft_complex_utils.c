/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:08:24 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/25 15:48:54 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_complex(t_complex *a, double x, double y)
{
	a->x = x;
	a->y = y;
}

t_complex	get_complex(double x, double y)
{
	t_complex	a;

	a.x = x;
	a.y = y;
	return (a);
}

t_complex	square_complex(t_complex a)
{
	t_complex	ret;

	ret.x = a.x * a.x - a.y * a.y;
	ret.y = 2 * a.x * a.y;
	return (ret);
}

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

t_complex	sub_complex(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	return (ret);
}
