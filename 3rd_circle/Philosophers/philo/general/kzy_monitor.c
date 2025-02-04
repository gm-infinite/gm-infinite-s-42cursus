/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:41:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/04 15:33:00 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	monitor_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input.number_of_philo)
	{
		pthread_mutex_lock(data->all_philosophers[i].death);
		if (get_time_now() - data->all_philosophers[i].last_eaten >= \
		data->input.time_to_die)
		{
			pthread_mutex_lock(&(data->write));
			data->sim_status = 0;
			printf("%ld %d died\n", get_time_now() - data->start_time, i + 1);
			pthread_mutex_unlock(&(data->write));
			pthread_mutex_unlock(data->all_philosophers[i].death);
			break ;
		}
		pthread_mutex_unlock(data->all_philosophers[i].death);
		i++;
	}
}

static void	monitor_must_eat(t_data *data)
{
	int	i;

	if (data->sim_status == 0)
		return ;
	i = 0;
	if (data->input.must_eat_number > 0)
	{
		while (i < data->input.number_of_philo)
		{
			if (data->all_philosophers[i].eaten_amouth < \
			data->input.must_eat_number)
				break ;
			i++;
		}
	}
	if (i == data->input.number_of_philo)
		data->sim_status = 0;
}

void	*monitor_start(void *thread_arg)
{
	t_data	*data;

	data = (t_data *)thread_arg;
	while (data->sim_status == 1)
	{
		monitor_death(data);
		monitor_must_eat(data);
	}
	return (NULL);
}

void	init_monitor(t_data *data)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, monitor_start, data) != 0)
	{
		data->sim_error = 3;
		printf("[\e[0;31mERROR\e[0m] pthread_create(...) in init_monitor \
returned error\n");
	}
	else
		pthread_join(monitor, NULL);
}
