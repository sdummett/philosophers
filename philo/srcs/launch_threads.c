/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:56:48 by sdummett          #+#    #+#             */
/*   Updated: 2022/01/02 18:05:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	launch_threads(t_datas *datas)
{
	int		i;

	i = 0;
	datas->simulation_start = gettime() + 1000;
	if (datas->philo_number == 1)
	{
		pthread_create(datas->philo_thread[i], NULL,
			&solo_philosopher_routine, datas->philo[i]);
		return ;
	}
	while (i < datas->philo_number)
	{
		pthread_create(datas->philo_thread[i], NULL,
			&philosopher_routine, datas->philo[i]);
		i++;
	}
}
