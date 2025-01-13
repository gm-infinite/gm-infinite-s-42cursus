/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:42 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/13 17:53:25 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_abs(int k)
{
	if (k < 0)
		return (-k);
	return (k);
}

/* static void final_push(t_list_ps **a, t_list_ps **b, int check[])
{

} */

static int getvalue(t_list_ps *a, t_list_ps *b, int size, int rot)
{
	int temp;
	t_list_ps *gsn;
	int gsnn;

	temp = rot * (rot > 0) + (size + rot) * (rot < 0);
	while ( temp-- > 0)
		a = a->next;
	gsn = b;
	gsnn = 0;
	temp = 1;
	while (gsn != NULL)
	{
		if (gsn->id < a->id && gsn->id > gsnn)
			gsnn = temp;
		gsn = gsn->next;
		temp++;
		ft_printf("gsnn:%d\n", gsnn);
	}
	if ((gsnn - 1) * 2 >= ft_lstsize_ps(b))
			gsnn = (gsnn - ft_lstsize_ps(b) - 1);
	return gsnn;
	
}

static void push_best(t_list_ps **a, t_list_ps **b, int size)
{
	int check[2];
	int rot;
	int value;
	t_list_ps *tempa;

	rot = 0;
	check[0] = __INT_MAX__ / 2;
	check[1] = __INT_MAX__ / 2;
	tempa = *a;
	while (tempa != NULL && ft_lstsize_ps(tempa) > 0)
	{
		if (2 * rot - 2 >= size)
			rot = rot - size ;
		value = ft_abs(check[0]) + ft_abs(check[1]) + 1;
		if (value > ft_abs(rot) + ft_abs(getvalue(*a, *b, size, rot)))
		{
			check[0] = rot;
			check[1] = getvalue(*a, *b, size, rot);
		}
		ft_printf("rot:%d--getvalue:%d\n", rot, getvalue(*a, *b, size, rot));
		rot++;
		tempa = tempa->next;
	}
	threeelementsort(a, ft_lstsize_ps(*a));
	ft_printf("a val:%d\nb val:%d\n", check[0], check[1]);
	//final_push(**a, **b, check);
}
void ft_turk_alg(t_list_ps **a, t_list_ps **b)
{
	p_aorb(0, a, b);
	p_aorb(0, a, b);
	r_aorb(1, b);
	p_aorb(0, a, b);
	p_aorb(0, a, b);
	r_aorb(1, b);
	r_aorb(1, b);
	p_aorb(0, a, b);
	rr_aorb(1, b);
	rr_aorb(0, a);
	p_aorb(0 , a, b);
		push_best(a, b, ft_lstsize_ps(*a));
}