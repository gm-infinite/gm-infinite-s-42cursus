/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:58:17 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/11/24 10:00:16 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void KO_output(t_list_ps **a, t_list_ps **b, char *line)
{
	ft_printf("KO\n");
	ft_lstclear_ps(a);
	ft_lstclear_ps(b);
	free(line);
	exit(0);
}

static void get_result2(t_list_ps **a, t_list_ps **b, char *line)
{
	if (ft_strncmp("rra\n", line, 4) == 0)
		rr_aorb(a);
	else if (ft_strncmp("rrb\n", line, 4) == 0)
		rr_aorb(b);
	else if (ft_strncmp("rrr\n", line, 4) == 0)
		rrr(a, b);
	else if (ft_strncmp("pa\n", line, 3) == 0)
		p_aorb(a, b);
	else if (ft_strncmp("pb\n", line, 3) == 0)
		p_aorb(b, a);
	else
		KO_output(a, b, line);
}

static void get_result(t_list_ps **a, t_list_ps **b)
{
	char *line;

	while((line = get_next_line(0)) != NULL)
	{
		if (ft_strncmp("sa\n", line, 3) == 0)
			s_aorb(a);
		else if (ft_strncmp("sb\n", line, 3) == 0)
			s_aorb(b);
		else if (ft_strncmp("ss\n", line, 3) == 0)
			ss(a, b);
		else if (ft_strncmp("ra\n", line, 3) == 0)
			r_aorb(a);
		else if (ft_strncmp("rb\n", line, 3) == 0)
			r_aorb(b);
		else if (ft_strncmp("rr\n", line, 3) == 0)
			rr(a, b);
		else 
			get_result2(a, b, line);
		free(line);
	}
}

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
    get_result(&a, &b);
	if (b == NULL && issorted(a) == 1 )
		ft_printf("OK\n");
	else 
		ft_printf("KO\n");
	ft_lstclear_ps(&a);
	ft_lstclear_ps(&b);

}