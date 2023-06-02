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

int	check_death(t_philos *philos, int mode)
{
	int	dieded;

	if (!mode)
	{
		pthread_mutex_lock(&philos->pdata->check_death);
		dieded = philos->pdata->has_died;
		pthread_mutex_unlock(&philos->pdata->check_death);
		return (dieded);
	}
	if (mode)
	{
		pthread_mutex_lock(&philos->pdata->check_death);
		philos->pdata->has_died = 1;
		pthread_mutex_unlock(&philos->pdata->check_death);
		return (1);
	}
	return (0);
}

int	trylock(t_philos *philos, char side)
{
	int	haslocked;

	haslocked = 0;
	if (side == 'L')
	{
		pthread_mutex_lock(philos->check_state_l);
		haslocked = *philos->state_l;
		pthread_mutex_unlock(philos->check_state_l);
		return (haslocked);
	}
	if (side == 'R')
	{
		pthread_mutex_lock(&philos->check_state_r);
		haslocked = philos->state_r;
		pthread_mutex_unlock(&philos->check_state_r);
		return (haslocked);
	}
	return (0);
}

int	smartsleep(int time, t_philos *philos)
{
	int	timestamp;
	int	delta;

	delta = get_timestamp(philos->pdata, 0);
	timestamp = delta;
	while (timestamp - delta < time && !check_death(philos, 0))
	{
		timestamp = get_timestamp(philos->pdata, 0);
		if (timestamp - philos->last_eaten > philos->pdata->time_die)
		{
			philo_actions(philos, philos->id, 4);
			return (check_death(philos, 1));
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
		pthread_mutex_init(&(pdata->philo[i].check_state_r), NULL);
		pdata->philo->state_r = 0;
		if (i > 0)
		{
			pdata->philo[i].fork_l = &pdata->philo[i - 1].fork_r;
			pdata->philo[i].state_l = &pdata->philo[i - 1].state_r;
			pdata->philo[i].check_state_l = &pdata->philo[i - 1].check_state_r;
		}
		if (i == amount - 1)
		{
			pdata->philo[0].fork_l = &pdata->philo[i].fork_r;
			pdata->philo[0].state_l = &pdata->philo[i].state_r;
			pdata->philo[0].check_state_l = &pdata->philo[i].check_state_r;
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
