/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:43:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/14 18:00:36 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printa(t_list_ps *a)
{
	ft_printf("id:%5d value:%5d\n", a->id, a->org_value);
	a = a->next;
	while (a != NULL)
	{
		ft_printf("id:%5d value:%5d\n", a->id, a->org_value);
		a = a->next;
	}
}

/* static int wordcount(char **list)
{
	int wc;

	wc = 0;
	while (list[wc] != NULL)
		wc++;
	return (wc);
} */

int main(int argc, char **argv)
{
	t_list_ps *a;
	t_list_ps *b;
	char **numberlist;
	int k;

	k = 0;
	numberlist = ft_normalize_argv(argc, argv, &k);
	isinputcorrect(k, argv, numberlist, argc);
	a = stackaset(k, numberlist);
	b = NULL;
	//printa(a);
	if (issorted(&a, ft_lstsize_ps(a)) == 1)
		return (ft_lstclear_ps(&a), 0);
	if (ft_lstsize_ps(a) < 4)
		threeelementsort(&a, ft_lstsize_ps(a), 0);
	else
		ft_turk_alg(&a, &b);
	issorted(&a, ft_lstsize_ps(a));
	//printa(a);
	//ft_printf("--------------\n");
	//printa(b);
	ft_lstclear_ps(&a);
	//ft_lstclear_ps(&b);
}
