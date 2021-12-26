/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simulation_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:07:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 16:51:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	get_simulation_data(t_datas *datas, char **args)
{
	datas->philo_number = ft_atoi(args[0]);
	datas->time_to_die = ft_atoi(args[1]);
	datas->time_to_eat = ft_atoi(args[2]);
	datas->time_to_sleep = ft_atoi(args[3]);
	if (args[4] != NULL)
		datas->time_must_eat = ft_atoi(args[4]);
	else
		datas->time_must_eat = -1;
	datas->forks_name = ft_strdup("forks");
	datas->someone_speak_name = ft_strdup("someone_speak");
	datas->someone_died_name = ft_strdup("someone_died");
	datas->confirm_someone_died_name = ft_strdup("confirm_someone_died");
	datas->forks_sem = sem_open(datas->forks_name, O_CREAT, S_IRUSR | S_IWUSR, (unsigned int)datas->philo_number);
	datas->someone_speak_sem = sem_open(datas->someone_speak_name, O_CREAT, S_IRUSR | S_IWUSR, (unsigned int)1);
	datas->someone_died_sem = sem_open(datas->someone_died_name, O_CREAT, S_IRUSR | S_IWUSR, (unsigned int)1);
}
