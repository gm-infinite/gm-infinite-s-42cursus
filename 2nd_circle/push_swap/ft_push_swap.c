/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:43:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/13 17:26:21 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printa(t_list_ps *a)
{
	ft_printf("id:%5d value:%5d\n", a->id, a->org_value);
	t_list_ps *temp = a->next;
	while (temp != NULL)
	{
		ft_printf("id:%5d value:%5d\n", temp->id, temp->org_value);
		temp = temp->next;
	}
}

int main(int argc, char **argv)
{
	t_list_ps *a;
	t_list_ps *b;

	isinputcorrect(argc - 1, argv);
	a = stackaset(argc, argv);
	b = NULL;
	printa(a);
	if (issorted(&a, ft_lstsize_ps(a)) == 1)
		return (0);
	if (ft_lstsize_ps(a) < 4)
		threeelementsort(&a, ft_lstsize_ps(a));
	else
		ft_turk_alg(&a, &b);
	printa(a);
	ft_printf("--------------\n");
	printa(b);
	ft_lstclear_ps(&a);
}
