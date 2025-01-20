/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:42 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:54:35 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_push2(t_list_ps **a, t_list_ps **b, int check[])
{
	while (check[0] < 0)
	{
		rr_aorb(0, a);
		check[0]++;
	}
	while (check[0] > 0)
	{
		r_aorb(0, a);
		check[0]--;
	}
	while (check[1] < 0)
	{
		rr_aorb(1, b);
		check[1]++;
	}
	while (check[1] > 0)
	{
		r_aorb(1, b);
		check[1]--;
	}
}

static void	final_push(t_list_ps **a, t_list_ps **b, int check[])
{
	while (check[0] < 0 && check[1] < 0)
	{
		rr_aorb(2, a);
		rr_aorb(2, b);
		ft_printf("rrr\n");
		check[0]++;
		check[1]++;
	}
	while (check[0] > 0 && check[1] > 0)
	{
		r_aorb(2, a);
		r_aorb(2, b);
		ft_printf("rr\n");
		check[0]--;
		check[1]--;
	}
	final_push2(a, b, check);
	p_aorb(0, a, b);
}

static void	push_best(t_list_ps **a, t_list_ps **b, int size, int check[])
{
	int			rot;
	int			value;
	t_list_ps	*tempa;

	rot = 0;
	tempa = *a;
	while (tempa != NULL && ft_lstsize_ps(tempa) > 0)
	{
		if (rot > size / 2)
			rot = rot - size;
		value = getbvalue(*a, *b, size, rot);
		if (value_calc(rot, value) < value_calc(check[0], check[1]))
		{
			check[0] = rot;
			check[1] = value;
		}
		rot++;
		tempa = tempa->next;
	}
}

void	ft_turk_alg(t_list_ps **a, t_list_ps **b)
{
	int	check[2];
	int	i;

	i = 0;
	while (ft_lstsize_ps(*a) > 3 && i++ < 2)
		p_aorb(0, a, b);
	while (ft_lstsize_ps(*a) > 3)
	{
		check[0] = __INT_MAX__ / 2;
		check[1] = __INT_MAX__ / 2;
		push_best(a, b, ft_lstsize_ps(*a), check);
		final_push(a, b, check);
	}
	threeelementsort(a, ft_lstsize_ps(*a), 0);
	ft_turk_alg_pb(b, a);
}
