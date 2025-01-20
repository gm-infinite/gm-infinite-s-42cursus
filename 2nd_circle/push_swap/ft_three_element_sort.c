/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_element_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:27:54 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:39:31 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	threeelementsort_m2(t_list_ps **a, int flag, int order[])
{
	if ((order[0] == 2 && order[1] == 1) || (order[0] == 1 && order[1] == 0)
		|| (order[0] == 0 && order[1] == 2))
		s_aorb(flag, a);
	if (order[2] == 0)
		rr_aorb(flag, a);
	if (order[2] == 1)
		r_aorb(flag, a);
}

void	threeelementsort(t_list_ps **a, int size, int flag)
{
	int	order[3];

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->id > (*a)->next->id)
			s_aorb(flag, a);
		return ;
	}
	order[0] = ((*a)->id > (*a)->next->id) + ((*a)->id > (*a)->next->next->id);
	order[1] = ((*a)->next->id > (*a)->id)
		+ ((*a)->next->id > (*a)->next->next->id);
	order[2] = ((*a)->next->next->id > (*a)->id)
		+ ((*a)->next->next->id > (*a)->next->id);
	if (size == 3)
		threeelementsort_m2(a, flag, order);
}
