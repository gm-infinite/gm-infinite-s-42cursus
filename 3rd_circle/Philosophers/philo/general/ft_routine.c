/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:47:29 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/04 17:02:18 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philo_start(void *thread_id)
{
	t_philosopher	*p;

	p = (t_philosopher *)thread_id;
	if (p->input->number_of_philo == 1)
		write_message(p, "%ld %d has taken a fork\n");
	else
	{
		while (*(p->sim_status) == 1)
		{
			write_message(p, "%ld %d is thinking\n");
			philo_eat(p);
			philo_sleep(p);
		}
	}
	return (NULL);
}

void	ft_usleep(unsigned long howlong, t_philosopher *p)
{
	unsigned long	start;

	start = get_time_now();
	while (*(p->sim_status) == 1 && get_time_now() - start < howlong)
		usleep(100);
}

void	write_message(t_philosopher *p, const char *str)
{
	if (*(p->sim_status) != 0)
	{
		pthread_mutex_lock(p->write);
		printf(str, get_time_now() - p->birthms, p->id);
		pthread_mutex_unlock(p->write);
	}
}

void	philo_eat(t_philosopher *p)
{
	pthread_mutex_lock(p->l_fork);
	write_message(p, "%ld %d has taken a fork\n");
	pthread_mutex_lock(p->r_fork);
	write_message(p, "%ld %d has taken a fork\n");
	write_message(p, "%ld %d is eating\n");
	if (*(p->sim_status) == 1)
	{
		pthread_mutex_lock(p->death);
		p->last_eaten = get_time_now();
		pthread_mutex_unlock(p->death);
		ft_usleep(p->input->time_to_eat, p);
		p->eaten_amouth++;
	}
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(p->l_fork);
}

void	philo_sleep(t_philosopher *p)
{
	write_message(p, "%ld %d is sleeping\n");
	ft_usleep(p->input->time_to_sleep, p);
}
