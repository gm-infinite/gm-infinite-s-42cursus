/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:42:58 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/13 11:41:08 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstadd_back_special(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*roamer;

	if ((*lst) != NULL)
	{
		roamer = *lst;
		while (roamer->next != NULL)
		{
			if (roamer->org_value < new->org_value)
				new->id++;
			else 
				roamer->id++;
			roamer = roamer->next;
		}
			if (roamer->org_value < new->org_value)
				new->id++;
			else 
				roamer->id++;
			roamer->next = new;
	}
	else
		*lst = new;
}

t_list_ps *stackaset(int argc, char **argv)
{
	t_list_ps	*stacka;
	int			i;

	i = 1;
	stacka = NULL;
	while (i < argc)
	{
		ft_lstadd_back_special(&stacka, ft_lstnew_ps(ft_atoi(argv[i])));
		i++;
	}
	return (stacka);
}