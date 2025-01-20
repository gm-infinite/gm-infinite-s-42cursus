/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:42 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:40:43 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int k)
{
	if (k < 0)
		return (-k);
	return (k);
}

int	value_calc(int a, int b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(a);
	abs_b = ft_abs(b);
	if ((a < 0 && b < 0) || (a > 0 && b > 0))
		return ((abs_a * (abs_a > abs_b)) + (abs_b * (abs_a <= abs_b)));
	else
		return (ft_abs(a - b));
}
