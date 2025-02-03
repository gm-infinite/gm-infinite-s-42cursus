/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:32:02 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/03 17:12:57 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static t_philosopher	*get_all_philosophers(int nop, t_data *data)
{
	t_philosopher	*all_philosophers;
	int				i;

	all_philosophers = ft_calloc(nop, sizeof(t_philosopher));
	i = 0;
	while(nop > i)
	{
		all_philosophers[i].id = i + 1;
		all_philosophers[i].forks = data->forks;
		all_philosophers[i].input = &(data->input);
		all_philosophers[i].write = data->write;
		all_philosophers[i].meta_fork = data->meta_fork;
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
			philo_start(&(data->all_philosophers[i]), data);
		}
		i++;
	}
}

void data_init(t_data *data, int argc, char **argv)
{
	data->input = input_init(argc, argv);
	sem_unlink("/ft_forks");
	sem_unlink("/ft_write");
	sem_unlink("/ft_meta_fork");
	data->forks = sem_open("/ft_forks", 0100, 0640, data->input.number_of_philo);
	data->write = sem_open("/ft_write", 0100, 0640, 1);
	data->meta_fork = sem_open("/ft_meta_fork", 0100, 0640, 1);
	data->all_philosophers = get_all_philosophers(data->input.number_of_philo, data);
	start_childs(data->input.number_of_philo, data);
}