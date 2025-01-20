/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getavalue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:42 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:53:56 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setminmax(int *min, int *max, t_list_ps *a)
{
	*min = __INT_MAX__;
	*max = -1;
	while (a != NULL)
	{
		if (a->id < *min)
			*min = a->id;
		if (a->id > *max)
			*max = a->id;
		a = a->next;
	}
}

static int	newminmax(t_list_ps *a, int size, int amin)
{
	int	rota;

	rota = 0;
	while (a != NULL && size > 0)
	{
		if (a->id == amin)
			break ;
		rota++;
		a = a->next;
	}
	if (rota > size / 2)
		rota = rota - size;
	return (rota);
}

static int	getavalue2(t_list_ps *b, t_list_ps *a, int size)
{
	int			gsn_rot;
	int			gsn;
	t_list_ps	*temp;

	gsn = __INT_MAX__;
	temp = a;
	gsn_rot = 0;
	while (temp != NULL)
	{
		if (temp->id > b->id && temp->id < gsn)
			gsn = temp->id;
		temp = temp->next;
	}
	while (a != NULL && a->id != gsn && size > 0)
	{
		gsn_rot++;
		a = a->next;
	}
	if (gsn_rot > size / 2)
		gsn_rot = gsn_rot - size;
	return (gsn_rot);
}

int	getavalue(t_list_ps *b, t_list_ps *a, int size, int rot)
{
	int	temp;
	int	amax;
	int	amin;

	temp = rot * (rot > 0) + (size + rot) * (rot < 0);
	while (temp-- > 0)
		b = b->next;
	setminmax(&amin, &amax, a);
	if (b->id > amax || b->id < amin)
		return (newminmax(a, ft_lstsize_ps(a), amin));
	return (getavalue2(b, a, ft_lstsize_ps(a)));
}
