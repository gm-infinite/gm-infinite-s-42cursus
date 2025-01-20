/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:43:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 11:40:55 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	issorted(t_list_ps *stack)
{
	while (stack->next != NULL)
	{
		if (stack->id > stack->next->id)
			return (0);
		stack = stack->next;
	}
	return (1);
}
