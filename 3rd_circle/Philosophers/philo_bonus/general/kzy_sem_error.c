/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:39:09 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/04 15:40:47 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	sem_error_check(sem_t *sem)
{
	if (sem == SEM_FAILED)
		return (1);
	return (0);
}

void	sem_error(sem_t *forks, sem_t *write, sem_t *sim_stop, sem_t *meta_fork)
{
	int	error;

	error = 0;
	if (sem_error_check(forks) == 1)
		error += 1;
	if (sem_error_check(write) == 1)
		error += 2;
	if (sem_error_check(sim_stop) == 1)
		error += 4;
	if (sem_error_check(meta_fork) == 1)
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
