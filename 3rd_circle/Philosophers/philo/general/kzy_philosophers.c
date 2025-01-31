/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:36:24 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/31 13:55:48 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void wait_and_destroy(t_data *data)
{
	int i;

	i = data->input.number_of_philo - 1;
	while(data->sim_error == 0 && i >= 0)
	{
		pthread_join(data->all_philosophers[i].philosopher, NULL);
		i--;
	}
	i = data->input.number_of_philo - 1;
	while(i >= 0)
	{
		pthread_mutex_destroy(&(data->death[i]));	
		pthread_mutex_destroy(&(data->forks[i]));
		i--;
	}
	pthread_mutex_destroy(&(data->write));
	free(data->all_philosophers);
	free(data->forks);
	free(data->death);
}

int	main(int argc, char **argv)
{
	t_data data;

	error_check(argc, argv);
	data_init(&data, argc, argv);
	init_monitor(&data);
	wait_and_destroy(&data);
	if (data.sim_error != 0)
		printf("[\e[0;31mERROR\e[0m] pthread_create(...); returned error NO:%d", data.sim_error);
}
