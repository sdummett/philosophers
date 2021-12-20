/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:47:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/20 20:22:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	place_forks(t_philo *philo)
{
	int	tmp;

	if (philo->id == 0)
		philo->right_fork = philo->datas->philo_number - 1;
	else
		philo->right_fork = philo->id - 1;
	philo->left_fork = philo->id ;
	if (philo->left_fork > philo->right_fork)
	{
		tmp = philo->left_fork;
		philo->left_fork = philo->right_fork;
		philo->right_fork = tmp;
	}
	printf("Philo %d: left_fork => %d | right_fork => %d\n",
		philo->id, philo->left_fork, philo->right_fork);
}

t_philo	**init_philos(t_datas *datas)
{
	int		i;
	t_philo	**philo;

	philo = malloc(sizeof(t_philo *) * datas->philo_number);
	datas->philo = malloc(sizeof(pthread_t *) * datas->philo_number);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->philo[i] = malloc(sizeof(pthread_t));
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->id = i;
		philo[i]->datas = datas;
		place_forks(philo[i]);
		i++;
	}
	return (philo);
}
