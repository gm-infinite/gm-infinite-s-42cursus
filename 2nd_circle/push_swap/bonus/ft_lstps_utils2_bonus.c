/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstps_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:27:54 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:46:11 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*roamer;

	new->next = NULL;
	if ((*lst) != NULL)
	{
		roamer = ft_lstlast_ps(*lst);
		roamer->next = new;
	}
	else
		*lst = new;
}
