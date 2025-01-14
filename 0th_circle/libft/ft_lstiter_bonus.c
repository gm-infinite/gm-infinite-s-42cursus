/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:47:38 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/10/15 12:54:02 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*roamer;

	if (lst == NULL)
		return ;
	roamer = lst;
	while (roamer != NULL)
	{
		f(roamer -> content);
		roamer = roamer -> next;
	}
}
