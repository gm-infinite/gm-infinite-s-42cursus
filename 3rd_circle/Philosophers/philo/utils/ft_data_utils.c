/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:32:02 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/04 16:50:46 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static pthread_mutex_t	*get_mutexs(int nop, int *error)
{
	pthread_mutex_t	*mutexs;

	mutexs = (pthread_mutex_t *)ft_calloc(nop, sizeof(pthread_mutex_t));
	if (mutexs == NULL)
		*error = -1;
	if (mutexs == NULL)
		return (NULL);
	nop--;
	while (nop >= 0 && *error == 0)
	{
		*error = pthread_mutex_init(&(mutexs[nop]), NULL);
		nop--;
	}
	return (mutexs);
}

static t_philosopher	*get_all_philosophers(int nop, t_data *data, int *error)
{
	t_philosopher	*all_philosophers;
	int				i;

	all_philosophers = ft_calloc(nop, sizeof(t_philosopher));
	if (all_philosophers == NULL)
		*error = -1;
	if (all_philosophers == NULL)
		return (NULL);
	i = 0;
	data->start_time = get_time_now();
	while (nop > i && *error == 0)
	{
		all_philosophers[i].id = i + 1;
		all_philosophers[i].l_fork = &(data->forks[i]);
		all_philosophers[i].r_fork = &(data->forks[(i + 1) % nop]);
		all_philosophers[i].input = &(data->input);
		all_philosophers[i].write = &(data->write);
		all_philosophers[i].birthms = (data->start_time);
		all_philosophers[i].death = &(data->death[i]);
		all_philosophers[i].sim_status = &(data->sim_status);
		all_philosophers[i].eaten_amouth = 0;
		all_philosophers[i].last_eaten = get_time_now();
		i++;
	}
	return (all_philosophers);
}

static void	start_threads(int nop, t_data *data)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < nop)
	{
		check = check | \
		pthread_create(&(data->all_philosophers[i].philosopher), \
		NULL, philo_start, &(data->all_philosophers[i]));
		i++;
		usleep(100);
	}
	if (check != 0)
	{
		data->sim_status = 0;
		data->sim_error = 1;
	}
}

void	data_init(t_data *data, int argc, char **argv)
{
	int	error;

	error = 0;
	data->input = input_init(argc, argv);
	data->forks = get_mutexs(data->input.number_of_philo, &error);
	data->death = get_mutexs(data->input.number_of_philo, &error);
	data->sim_status = 1;
	data->sim_error = 0;
	if (error == 0)
		error = pthread_mutex_init(&(data->write), NULL);
	data->all_philosophers = get_all_philosophers(data->input.number_of_philo, \
	data, &error);
	if (error != 0)
	{
		printf("[\e[0;31mERROR\e[0m] an error happened while initializing \
data. errNO:%4d", error);
		if (data->all_philosophers != NULL)
			free(data->all_philosophers);
		if (data->forks != NULL)
			free(data->forks);
		if (data->death != NULL)
			free(data->death);
		data->sim_error = 2;
	}
	else
		start_threads(data->input.number_of_philo, data);
}
