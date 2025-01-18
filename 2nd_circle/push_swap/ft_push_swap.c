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

int wordcount(char **list)
{
	int wc;

	wc = 0;
	while (list[wc] != NULL)
		wc++;
	return (wc);
}

int main(int argc, char **argv)
{
	t_list_ps *a;
	t_list_ps *b;
	char **numberlist;
	int k;

	k = 0;
	if (argv[1] != NULL && argc == 2)
	{
		numberlist = ft_split(argv[1], ' ');
		argc = wordcount(numberlist);
		k = 1;
	}
	else
		numberlist = argv;
	isinputcorrect(argc - 1, numberlist, k);
	a = stackaset(argc, numberlist, (k != 1));
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
