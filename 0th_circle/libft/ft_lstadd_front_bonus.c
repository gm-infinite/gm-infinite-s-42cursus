/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:20:31 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/10/15 10:33:10 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*cutter;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	cutter = *lst;
	*lst = new;
	(*lst)-> next = cutter;
}
