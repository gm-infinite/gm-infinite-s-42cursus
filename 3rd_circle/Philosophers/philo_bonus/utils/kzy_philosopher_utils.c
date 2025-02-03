/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kzy_philosopher_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:27:56 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/03 17:40:14 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philosopher copy_phisolopher(t_philosopher *p)
{
    t_philosopher ret;

    sem_init(&(ret.death), 0, 1);
    ret.sim_status = 1;
    ret.forks = p->forks;
    ret.id = p->id;
    ret.input = p->input;
    ret.meta_fork = p->meta_fork;
    ret.pid = p->pid;
    ret.write = p->write;
    ret.eaten_amouth = 0;
    ret.birthms = get_time_now();
    ret.last_eaten = ret.birthms;
    return (ret);
}