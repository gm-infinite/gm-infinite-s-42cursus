/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:24:50 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/13 11:28:47 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include "libft/libft.h"
# define __USE_XOPEN_EXTENDED
# define __USE_POSIX 1
# define __USE_XOPEN
# include <signal.h>

typedef struct s_client_needs
{
	char	*message;
	pid_t	pid;
	int		char_count;
	int		bit_count;
}			t_client_needs;

#endif