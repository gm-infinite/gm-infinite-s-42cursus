/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbvalue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:42 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:54:00 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setminmax(int *min, int *max, t_list_ps *b)
{
	*min = __INT_MAX__;
	*max = -1;
	while (b != NULL)
	{
		if (b->id < *min)
			*min = b->id;
		if (b->id > *max)
			*max = b->id;
		b = b->next;
	}
}

static int	newminmax(t_list_ps *b, int size, int bmax)
{
	int	rotb;

	rotb = 0;
	while (b != NULL && size > 0)
	{
		if (b->id == bmax)
			break ;
		rotb++;
		b = b->next;
	}
	if (rotb > size / 2)
		rotb = rotb - size;
	return (rotb);
}

static int	getbvalue2(t_list_ps *a, t_list_ps *b, int size)
{
	int			gsn_rot;
	int			gsn;
	t_list_ps	*temp;

	gsn = -1;
	temp = b;
	gsn_rot = 0;
	while (temp != NULL)
	{
		if (temp->id < a->id && temp->id > gsn)
			gsn = temp->id;
		temp = temp->next;
	}
	while (b != NULL && b->id != gsn && size > 0)
	{
		gsn_rot++;
		b = b->next;
	}
	if (gsn_rot > size / 2)
		gsn_rot = gsn_rot - size;
	return (gsn_rot);
}

int	getbvalue(t_list_ps *a, t_list_ps *b, int size, int rot)
{
	int	temp;
	int	bmax;
	int	bmin;

	temp = rot * (rot > 0) + (size + rot) * (rot < 0);
	while (temp-- > 0)
		a = a->next;
	setminmax(&bmin, &bmax, b);
	if (a->id > bmax || a->id < bmin)
		return (newminmax(b, ft_lstsize_ps(b), bmax));
	return (getbvalue2(a, b, ft_lstsize_ps(b)));
}
