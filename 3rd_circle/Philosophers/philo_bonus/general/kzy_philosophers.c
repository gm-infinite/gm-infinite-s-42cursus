/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:36:24 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/03 17:07:47 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	kill_all_child(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input.number_of_philo)
	{
		kill(data->all_philosophers[i].pid, SIGTERM);
		i++;
	}
}

static void	wait_and_destroy(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < data->input.number_of_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			kill_all_child(data);
			break ;
		}
		i++;
	}
	sem_unlink("/ft_forks");
	sem_unlink("/ft_write");
	sem_unlink("/ft_meta_forks");
	sem_close(data->forks);
	sem_close(data->write);
	sem_close(data->meta_fork);
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
