/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:07:28 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/10/15 11:27:53 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*roamer;

	if ((*lst) != NULL)
	{
		roamer = ft_lstlast(*lst);
		roamer -> next = new;
	}
	else
		*lst = new;
}