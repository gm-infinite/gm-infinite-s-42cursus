/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstps_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:27:54 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:48:49 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*ft_lstnew_ps(int v)
{
	t_list_ps	*newnode;

	newnode = malloc(sizeof(t_list_ps));
	if (!newnode)
		return (NULL);
	newnode->id = 0;
	newnode->org_value = v;
	newnode->next = NULL;
	return (newnode);
}

t_list_ps	*ft_lstlast_ps(t_list_ps *lst)
{
	t_list_ps	*roamer;

	if (lst == NULL)
		return (NULL);
	roamer = lst;
	while (roamer->next != NULL)
		roamer = roamer->next;
	return (roamer);
}

int	ft_lstsize_ps(t_list_ps *lst)
{
	int			size;
	t_list_ps	*roamer;

	if (lst == NULL)
		return (0);
	size = 1;
	roamer = lst;
	while (roamer->next != NULL)
	{
		roamer = roamer->next;
		size++;
	}
	return (size);
}

void	ft_lstclear_ps(t_list_ps **lst)
{
	t_list_ps	*roamer;
	t_list_ps	*follower;

	if (lst != NULL)
	{
		roamer = *lst;
		while (roamer != NULL)
		{
			follower = roamer;
			roamer = roamer->next;
			free(follower);
		}
	}
	*lst = NULL;
}

void	ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*cutter;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	cutter = *lst;
	*lst = new;
	(*lst)->next = cutter;
}
