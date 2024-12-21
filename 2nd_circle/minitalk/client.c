/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:29:25 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/13 12:24:55 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(t_client_needs client)
{
	int	bit;
	int	error;

	bit = (client.message[client.char_count] >> \
	(7 - client.bit_count)) % 2;
	if (bit == 1)
		error = kill(client.pid, SIGUSR2);
	else
		error = kill(client.pid, SIGUSR1);
	if (error == -1)
	{
		ft_printf("\e[37;31mkill returned -1\n \
\e[0m*probably server pid is wrong*\n");
		exit(0);
	}
}

void	value_setter(int flag, char *m_message, int m_pid, int signum)
{
	static t_client_needs	client;

	if (flag == 1)
	{
		client.message = m_message;
		client.pid = m_pid;
		return ;
	}
	if (signum == SIGUSR2)
		exit(0);
	send_signal(client);
	client.bit_count++;
	if (client.bit_count == 8)
	{
		client.char_count++;
		client.bit_count = 0;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void) info;
	(void) ucontext;
	value_setter(0, NULL, 0, signum);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		if (argc < 3)
			ft_printf("\e[37;31mERROR: not enough arguments\n");
		if (argc > 3)
			ft_printf("\e[37;31mERROR: too many arguments\n");
		ft_printf("\e[0mUSAGE: ./client <server_pid> <string>\n");
		return (1);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	value_setter(1, argv[2], ft_atoi(argv[1]), 0);
	signal_handler(SIGUSR1, NULL, NULL);
	while (1)
		pause();
}
