/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:23:12 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/14 16:24:20 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void p_aorb(int ab, t_list_ps **giver, t_list_ps **taker)
{
    t_list_ps *temp;

    if (!*giver)
        return;
    temp = *giver;
    *giver = (*giver)->next;
    temp->next = NULL;
    ft_lstadd_front_ps(taker, temp);
    
    if (ab == 0)
        ft_printf("pa\n");
    else if (ab == 1)
        ft_printf("pb\n");
}

void r_aorb(int ab, t_list_ps **rotate)
{
	t_list_ps *temp;

	temp = *rotate;
	*rotate = (*rotate)->next;
	ft_lstadd_back_ps(rotate, temp);
	if (ab == 0)
		ft_printf("ra\n");
	else if (ab == 1)
		ft_printf("rb\n");
}

void rr_aorb(int ab, t_list_ps **rotate)
{
	t_list_ps *temp;

	temp = *rotate;
	while (temp->next->next != NULL)
		temp = temp ->next;
	ft_lstadd_front_ps(rotate, temp->next);
    temp->next = NULL;
	if (ab == 0)
		ft_printf("rra\n");
	else	if (ab == 1)
		ft_printf("rrb\n");
}

void s_aorb(int ab, t_list_ps **swap)
{
	t_list_ps *temp;

	temp = *swap;
	*swap = (*swap)->next;
	temp->next = (*swap)->next;
	(*swap)->next = temp;
	if (ab == 0)
		ft_printf("sa\n");
	else if (ab == 1)
		ft_printf("sb\n");
}