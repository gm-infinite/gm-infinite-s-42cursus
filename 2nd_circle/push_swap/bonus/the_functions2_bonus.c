/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_functions2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:23:12 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/20 13:25:31 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_output(char **argv)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	if (argv == NULL)
		exit(1);
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	exit(1);
}

void	rr(t_list_ps **a, t_list_ps **b)
{
	if ((*a) != NULL)
		r_aorb(a);
	if ((*b) != NULL)
		r_aorb(b);
}

void	rrr(t_list_ps **a, t_list_ps **b)
{
	if ((*a) != NULL)
		rr_aorb(a);
	if ((*b) != NULL)
		rr_aorb(b);
}

void	ss(t_list_ps **a, t_list_ps **b)
{
	if ((*a) != NULL)
		s_aorb(a);
	if ((*b) != NULL)
		s_aorb(b);
}
