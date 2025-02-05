/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:41:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/05 16:29:19 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

static void	monitor_death(t_philosopher *p)
{
	int	death;

	sem_wait(&(p->death));
	death = get_time_now() - p->last_eaten;
	if (death >= p->input->time_to_die)
	{
		sem_wait(p->write);
		p->sim_status = 0;
		printf("%ld %d died\n", get_time_now() - *(p->birthms), p->id);
		sem_post(p->sim_stop);
		sem_wait(&p->death);
	}
	sem_post(&(p->death));
}

static void	monitor_must_eat(t_philosopher *p)
{
	if (p->input->must_eat_number > 0)
	{
		if (p->eaten_amouth >= p->input->must_eat_number + 3)
			sem_post(p->sim_stop);
	}
}

static void	*monitor_start(void *thread_arg)
{
	t_philosopher	*p;

	p = (t_philosopher *)thread_arg;
	while (1)
	{
		monitor_death(p);
		monitor_must_eat(p);
		usleep(1000);
	}
}

void	init_monitor(t_philosopher *p, pthread_t *monitor)
{	
	if (pthread_create(monitor, NULL, monitor_start, p) != 0)
	{
		sem_wait(p->write);
		printf("%d had an problem when initiating monitor", p->id);
		sem_post(p->sim_stop);
	}
}
