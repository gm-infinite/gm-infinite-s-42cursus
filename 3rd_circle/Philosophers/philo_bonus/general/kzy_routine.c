/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:47:29 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/03 17:59:30 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_start(t_philosopher *p_t, t_data *to_free)
{
	pthread_t		monitor;
	t_philosopher	p;

	p = copy_phisolopher(p_t);
	init_monitor(&p, &monitor);
	if (p.id % 2 == 0)
		usleep(500);
	free(to_free->all_philosophers);
	while (p.sim_status == 1)
	{
		philo_eat(&p);
		philo_sleep(&p);
	}
	sem_close(to_free->forks);
	sem_close(to_free->write);
	pthread_join(monitor, NULL);
	if (p.sim_status == 0)
		exit(1);
	exit(0);
}

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
	printf(str, get_time_now() - p->birthms, p->id);
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
	write_message(p, "%ld %d is thinking\n");
}
