/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:36:24 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/05 16:29:19 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	kill_all_child(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input.number_of_philo)
	{
		kill(data->all_philosophers[i].pid, SIGKILL);
		i++;
	}
}

static void	wait_and_destroy(t_data *data)
{
	sem_wait(data->sim_stop);
	kill_all_child(data);
	sem_unlink("/ft_forks");
	sem_unlink("/ft_write");
	sem_unlink("/ft_meta_forks");
	sem_unlink("/ft_sim_stop");
	sem_close(data->forks);
	sem_close(data->write);
	sem_close(data->meta_fork);
	sem_close(data->sim_stop);
	free(data->all_philosophers);
}

int	main(int argc, char **argv)
{
	t_data	data;

	error_check(argc, argv);
	data_init(&data, argc, argv);
	wait_and_destroy(&data);
	return (0);
}
