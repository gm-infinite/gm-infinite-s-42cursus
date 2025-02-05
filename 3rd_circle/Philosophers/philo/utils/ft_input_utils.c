/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_input_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:36:11 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/03 16:16:03 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_input	input_init(int argc, char **argv)
{
	t_input	ret;

	ret.number_of_philo = ft_atoi(argv[1]);
	ret.time_to_die = ft_atoi(argv[2]);
	ret.time_to_eat = ft_atoi(argv[3]);
	ret.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		ret.must_eat_number = -1;
	else
		ret.must_eat_number = ft_atoi(argv[5]);
	return (ret);
}
