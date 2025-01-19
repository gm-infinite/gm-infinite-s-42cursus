/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:43:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/14 11:52:42 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int issorted2(t_list_ps *idsmallest, t_list_ps *last)
{
	t_list_ps *roamer;

	roamer = idsmallest;
	while (roamer->id < roamer->next->id)
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

int issorted(t_list_ps *a)
{
	t_list_ps	*last;
	t_list_ps	*idsmallest;
	int			sdistance;
	int check;

	idsmallest = a;
	last = ft_lstlast_ps(a);
	last->next = a;
	sdistance = 0;
	while (idsmallest->id != 0)
	{
		idsmallest = idsmallest->next;
		sdistance++;
	}
	if ((check = issorted2(idsmallest, last)) == 0)
		return (0);
	return (1);
}
