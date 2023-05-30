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

int	minisleep(int time, t_philos *philos)
{
	int	timestamp;

	time = time * 2;
	while (--time != -1 && philos->pdata->has_died != 1)
	{
		timestamp = get_timestamp(philos->pdata, 0);
		printf("timestamp is %d in thread %d\n", timestamp, philos->id);
		printf("you know %d\n", philos->last_eaten - timestamp);
		if (philos->last_eaten - timestamp < 0)
		{
			philo_actions(philos, timestamp, philos->id, 4);
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
		pdata->philo[i].last_eaten = pdata->time_die;
		printf("last eaten time set to %d\n", pdata->philo[i].last_eaten);
		pthread_mutex_init(&(pdata->philo[i].fork_r), NULL);
		if (i > 0)
			pdata->philo[i].fork_l = &pdata->philo[i - 1].fork_r;
		if (i == amount - 1)
			pdata->philo[0].fork_l = &pdata->philo[i].fork_r;
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
