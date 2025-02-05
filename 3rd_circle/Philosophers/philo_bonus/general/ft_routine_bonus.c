/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:47:29 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/05 16:29:19 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	ft_usleep(unsigned long howlong)
{
	unsigned long	start;

	start = get_time_now();
	while (get_time_now() - start < howlong)
		usleep(100);
}

void	write_message(t_philosopher *p, const char *str)
{
	sem_wait(p->write);
	printf(str, get_time_now() - *(p->birthms), p->id);
	sem_post(p->write);
}

void	philo_eat(t_philosopher *p)
{
	sem_wait(p->meta_fork);
	sem_wait(p->forks);
	sem_post(p->meta_fork);
	write_message(p, "%ld %d has taken a fork\n");
	sem_wait(p->meta_fork);
	sem_wait(p->forks);
	sem_post(p->meta_fork);
	write_message(p, "%ld %d has taken a fork\n");
	sem_wait(&(p->death));
	p->last_eaten = get_time_now();
	sem_post(&(p->death));
	write_message(p, "%ld %d is eating\n");
	ft_usleep(p->input->time_to_eat);
	p->eaten_amouth++;
	sem_post(p->forks);
	sem_post(p->forks);
}

void	philo_sleep(t_philosopher *p)
{
	write_message(p, "%ld %d is sleeping\n");
	ft_usleep(p->input->time_to_sleep);
}

void	philo_start(t_philosopher *p)
{
	pthread_t		monitor;

	if (sem_init(&(p->death), 0, 1) != 0)
	{
		sem_wait(p->write);
		printf("%d could not initiate \"death\" semaphor", p->id);
		sem_post(p->sim_stop);
	}
	p->last_eaten = *(p->birthms);
	init_monitor(p, &monitor);
	if (p->id % 2 == 0)
		usleep(500);
	while (1)
	{
		write_message(p, "%ld %d is thinking\n");
		philo_eat(p);
		philo_sleep(p);
	}
}
