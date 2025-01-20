/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:23:12 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 13:10:05 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	p_aorb(t_list_ps **giver, t_list_ps **taker)
{
	t_list_ps	*temp;

	if (!*giver)
		return ;
	temp = *giver;
	*giver = (*giver)->next;
	temp->next = NULL;
	ft_lstadd_front_ps(taker, temp);
}

void	r_aorb(t_list_ps **rotate)
{
	t_list_ps	*temp;

	if (!*rotate || ft_lstsize_ps(*rotate) == 1)
		return ;
	temp = *rotate;
	*rotate = (*rotate)->next;
	ft_lstadd_back_ps(rotate, temp);
}

void	rr_aorb(t_list_ps **rotate)
{
	t_list_ps	*temp;

	if (!*rotate || ft_lstsize_ps(*rotate) == 1)
		return ;
	temp = *rotate;
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_lstadd_front_ps(rotate, temp->next);
	temp->next = NULL;
}

void	s_aorb(t_list_ps **swap)
{
	t_list_ps	*temp;

	if (!*swap)
		return ;
	temp = *swap;
	*swap = (*swap)->next;
	temp->next = (*swap)->next;
	(*swap)->next = temp;
}
