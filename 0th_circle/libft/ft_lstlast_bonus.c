/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:55:42 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/10/15 11:06:39 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*roamer;

	if (lst == NULL)
		return (NULL);
	roamer = lst;
	while (roamer -> next != NULL)
		roamer = roamer -> next;
	return (roamer);
}
