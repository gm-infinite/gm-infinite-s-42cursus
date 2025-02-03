/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:58 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/03 16:18:59 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

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
	long			birthms;
	long			last_eaten;
	int				*sim_status;
	int				eaten_amouth;
	pthread_t		philosopher;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*death;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write;
	t_input			*input;
}	t_philosopher;

typedef struct s_data {
	t_input			input;
	long			start_time;
	int				sim_status;
	int				sim_error;
	pthread_mutex_t	write;
	pthread_mutex_t	*death;
	pthread_mutex_t	*forks;
	t_philosopher	*all_philosophers;
}					t_data;

t_input	input_init(int argc, char **argv);
int		error_check(int argc, char **argv);
void	data_init(t_data *data, int argc, char **argv);
void	philo_eat(t_philosopher *p);
void	philo_sleep(t_philosopher *p);
void	*monitor_start(void *thread_arg);
long	get_time_now(void);
void	write_message(t_philosopher *p, const char *str);
void	*philo_start(void *thread_id);
void	init_monitor(t_data *data);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif