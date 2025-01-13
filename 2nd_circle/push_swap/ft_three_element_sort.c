/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_element_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:27:54 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/23 11:47:28 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void threeelementsort(t_list_ps **a, int size)
{
	if (size == 2)
	{
		if ((*a)->id < (*a)->next->id)
			ft_printf("sa");
	}
	else if (size == 3)
	{
		if ((*a)->id == 0 && (*a)->next->id == 1)
			ft_printf("sa\nrra\n");
		else if ((*a)->id == 0 && (*a)->next->id == 2)
			ft_printf("ra\n");
		else if ((*a)->id == 1 && (*a)->next->id == 0)
			ft_printf("rra\n");
		else if ((*a)->id == 1 && (*a)->next->id == 2)
			ft_printf("sa\n");
		else if ((*a)->id == 2 && (*a)->next->id == 0)
			ft_printf("sa\nra\n");
	}
}
