/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:32:02 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/05 16:29:19 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

static t_philosopher	*get_all_philosophers(int nop, t_data *data)
{
	t_philosopher	*all_philosophers;
	int				i;

	all_philosophers = ft_calloc(nop, sizeof(t_philosopher));
	if (all_philosophers == NULL)
		return (NULL);
	i = 0;
	while (nop > i)
	{
		all_philosophers[i].id = i + 1;
		all_philosophers[i].forks = data->forks;
		all_philosophers[i].input = &(data->input);
		all_philosophers[i].write = data->write;
		all_philosophers[i].meta_fork = data->meta_fork;
		all_philosophers[i].sim_stop = data->sim_stop;
		all_philosophers[i].birthms = &(data->start_time);
		all_philosophers[i].sim_status = 1;
		all_philosophers[i].eaten_amouth = 0;
		i++;
	}
	return (all_philosophers);
}

static void	start_childs(int nop, t_data *data)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < nop)
	{
		pid = fork();
		if (pid != 0)
			data->all_philosophers[i].pid = pid;
		if (pid == 0)
		{
			philo_start(&(data->all_philosophers[i]));
		}
		i++;
	}
}

void	data_init(t_data *data, int argc, char **argv)
{
	data->input = input_init(argc, argv);
	sem_unlink("/ft_forks");
	sem_unlink("/ft_write");
	sem_unlink("/ft_meta_fork");
	sem_unlink("/ft_sim_stop");
	data->forks = sem_open("/ft_forks", 0100, 0640, \
data->input.number_of_philo);
	data->write = sem_open("/ft_write", 0100, 0640, 1);
	data->meta_fork = sem_open("/ft_meta_fork", 0100, 0640, 1);
	data->sim_stop = sem_open("/ft_sim_stop", 0100, 0640, 0);
	sem_error(data->forks, data->write, data->sim_stop, data->meta_fork);
	data->all_philosophers = get_all_philosophers(data->input.number_of_philo, \
	data);
	if (data->all_philosophers == NULL)
	{
		printf("while allocating memory for philo's, malloc returned an error");
		sem_close(data->forks);
		sem_close(data->write);
		sem_close(data->meta_fork);
		sem_close(data->sim_stop);
		exit (1);
	}
	data->start_time = get_time_now();
	start_childs(data->input.number_of_philo, data);
}
