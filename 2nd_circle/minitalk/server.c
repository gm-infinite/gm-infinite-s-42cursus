/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:28:30 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/13 11:09:18 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	bit_count;
	static char	chr;

	(void) info;
	(void) ucontext;
	bit_count++;
	if (signum == SIGUSR2)
		chr = chr | 1;
	if (bit_count == 8)
	{
		if (chr == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_printf("%c", (char)chr);
		chr = 0;
		bit_count = 0;
	}
	chr = chr << 1;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				serverpid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	serverpid = getpid();
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID:%8d\n", serverpid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
