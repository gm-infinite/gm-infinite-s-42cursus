/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:58 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/07 12:36:44 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define __USE_POSIX 1
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <string.h>

typedef struct s_input {
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_number;
}		t_input;

typedef struct s_philosopher
{
	int				id;
	long			*birthms;
	long			last_eaten;
	int				eaten_amouth;
	int				sim_status;
	sem_t			*forks;
	sem_t			*meta_fork;
	sem_t			*write;
	sem_t			death;
	sem_t			*sim_stop;
	t_input			*input;
	pid_t			pid;
}	t_philosopher;

typedef struct s_data {
	t_input			input;
	long			start_time;
	sem_t			*forks;
	sem_t			*write;
	sem_t			*meta_fork;
	sem_t			*sim_stop;
	t_philosopher	*all_philosophers;
}					t_data;

t_input			input_init(int argc, char **argv);
void			error_check(int argc, char **argv);
void			data_init(t_data *data, int argc, char **argv);
void			philo_eat(t_philosopher *p);
void			philo_sleep(t_philosopher *p);
long			get_time_now(void);
void			write_message(t_philosopher *p, const char *str);
void			philo_start(t_philosopher *p);
void			init_monitor(t_philosopher *p, pthread_t *monitor);
void			sem_error(sem_t *forks, sem_t *write, sem_t *sim_stop, \
sem_t *meta_fork);

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);

#endif