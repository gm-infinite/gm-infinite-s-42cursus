/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:43:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 14:06:31 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_ps	*a;
	t_list_ps	*b;
	char		**numberlist;
	int			k;

	k = 0;
	if (argc < 2)
		return (0);
	numberlist = ft_normalize_argv(argc, argv, &k);
	isinputcorrect(k, argv, numberlist, argc);
	a = stackaset(k, numberlist);
	b = NULL;
	if (k == 0)
		return (0);
	if (issorted(&a, ft_lstsize_ps(a)) == 1)
		return (ft_lstclear_ps(&a), 0);
	if (ft_lstsize_ps(a) < 4)
		threeelementsort(&a, ft_lstsize_ps(a), 0);
	else
		ft_turk_alg(&a, &b);
	issorted(&a, ft_lstsize_ps(a));
	ft_lstclear_ps(&a);
}
