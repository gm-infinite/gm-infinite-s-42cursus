/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:43:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/23 16:07:13 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int issorted2(t_list_ps *idsmallest, t_list_ps *last)
{
	t_list_ps *roamer;

	roamer = idsmallest;
	while (roamer->id > roamer->next->id)
	{
		roamer = roamer->next;
		if (roamer->next == idsmallest)
		{
			last->next = NULL;
			return (1);
		}
	}
	last->next = NULL;
	return (0);
}

void sortraorrra(t_list_ps **a, int times, int way)
{
	if (way == 0)
	{
		while (times > 0)
		{
			r_aorb(0, a);
			times--;
		}
	}
	else if (way == 1)
	{
		while (times > 0)
		{
			rr_aorb(0, a);
			times--;
		}
	}
}

int issorted(t_list_ps **a, int asize)
{
	t_list_ps	*last;
	t_list_ps	*idsmallest;
	int			sdistance;
	int check;

	idsmallest = *a;
	last = ft_lstlast_ps(*a);
	last->next = *a;
	sdistance = 0;
	while (idsmallest->id != (asize - 1))
	{
		idsmallest = idsmallest->next;
		sdistance++;
	}
	if ((check = issorted2(idsmallest, last)) == 0)
		return (0);
	if (sdistance <= asize / 2)	
		sortraorrra(a, sdistance, 0);
	else
		sortraorrra(a, asize - sdistance, 1);
	return (1);
}