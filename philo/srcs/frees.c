/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:40:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 11:44:40 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_number)
	{
		free(philo->philo[i]);
		i++;
	}
	free(philo->philo);
}

void	free_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_number)
	{
		free(philo->fork_mutex[i]);
		i++;
	}
	free(philo->fork_mutex);
}

void	free_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_number)
	{
		free(philo->forks[i]);
		i++;
	}
	free(philo->forks);
}

void	frees(t_philo *philo)
{
	free_threads(philo);
	free_mutexes(philo);
	free_forks(philo);
}
