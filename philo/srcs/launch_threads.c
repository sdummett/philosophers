/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:56:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 15:02:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	launch_threads(t_datas *datas, t_philo **philo)
{
	int		i;

	i = 0;
	datas->simulation_start = gettime() + 1000;
	while (i < datas->philo_number)
	{
		philo[i]->real_time = gettime();
		pthread_create(datas->philo[i], NULL, &routine, philo[i]);
		i++;
	}
}
