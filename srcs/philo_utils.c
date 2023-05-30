/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:14:43 by fclivaz           #+#    #+#             */
/*   Updated: 2023/05/02 18:14:53 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	smartsleep(int time, t_philos *philos)
{
	int	timestamp;
	int	delta;

	delta = get_timestamp(philos->pdata, 0);
	timestamp = delta;
	while (timestamp - delta < time && philos->pdata->has_died != 1)
	{
		timestamp = get_timestamp(philos->pdata, 0);
		if (timestamp - philos->last_eaten > philos->pdata->time_die)
		{
			philo_actions(philos, philos->id, 4);
			philos->pdata->has_died = 1;
			return (1);
		}
		if (usleep(500) == -1)
			return (-1);
	}
	return (0);
}

void	pthread_init(t_pdata *pdata, int amount)
{
	int	i;

	i = -1;
	while (++i < amount)
	{
		pdata->philo[i].id = i + 1;
		pdata->philo[i].pdata = pdata;
		pthread_mutex_init(&(pdata->philo[i].fork_r), NULL);
		pdata->philo->state_r = 0;
		if (i > 0)
		{
			pdata->philo[i].fork_l = &pdata->philo[i - 1].fork_r;
			pdata->philo[i].state_l = &pdata->philo[i - 1].state_r;
		}
		if (i == amount - 1)
		{
			pdata->philo[0].fork_l = &pdata->philo[i].fork_r;
			pdata->philo[0].state_l = &pdata->philo[i].state_r;
		}
	}
}

int	get_timestamp(t_pdata *pdata, int mode)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	if (mode == 0)
		return ((((time.tv_sec * 1000000) + time.tv_usec) \
			- pdata->init) / 1000);
	pdata->init = (time.tv_sec * 1000000) + time.tv_usec;
	return (0);
}
