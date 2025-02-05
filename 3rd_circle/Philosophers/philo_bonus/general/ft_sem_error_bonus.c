/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:39:09 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/05 16:29:19 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	sem_error(sem_t *forks, sem_t *write, sem_t *sim_stop, sem_t *meta_fork)
{
	int	error;

	error = 0;
	if (forks == SEM_FAILED)
		error += 1;
	if (write == SEM_FAILED)
		error += 2;
	if (sim_stop == SEM_FAILED)
		error += 4;
	if (meta_fork == SEM_FAILED)
		error += 8;
	if (error > 0)
	{
		if ((error & 1) == 0)
			sem_close(forks);
		if (((error >> 1) & 1) == 0)
			sem_close(write);
		if (((error >> 2) & 1) == 0)
			sem_close(sim_stop);
		if (((error >> 3) & 1) == 0)
			sem_close(meta_fork);
		printf("sem_open(...) returned SEM_FAILED %d", error);
		exit(1);
	}
}
