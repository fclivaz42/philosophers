/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_moment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:45:51 by fclivaz           #+#    #+#             */
/*   Updated: 2023/05/10 16:45:58 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	take_forks(t_philos *philos, int mode)
{
	if (!mode)
		lock_unlock_madness(philos);
	if (mode)
	{
		pthread_mutex_unlock(philos->fork_l);
		pthread_mutex_lock(philos->check_state_l);
		*philos->state_l = 0;
		pthread_mutex_unlock(philos->check_state_l);
		pthread_mutex_unlock(&(philos->fork_r));
		pthread_mutex_lock(&(philos->check_state_r));
		philos->state_r = 0;
		pthread_mutex_unlock(&(philos->check_state_r));
	}
}

static void	philo_eat(t_philos *philos)
{
	take_forks(philos, 0);
	philo_actions(philos, philos->id, 1);
	philos->last_eaten = get_timestamp(philos->pdata, 0);
	smartsleep(philos->pdata->time_eat, philos);
	take_forks(philos, 1);
}

static void	philo_sleep(t_philos *philos)
{
	philo_actions(philos, philos->id, 2);
	smartsleep(philos->pdata->time_sleep, philos);
	if (check_death(philos, 0))
		return ;
	philo_actions(philos, philos->id, 3);
}	

void	*philo_routine(void *p)
{
	t_philos	*philos;
	int			eaten;

	eaten = -1;
	philos = (t_philos *)p;
	if (philos->id % 2 == 0)
		philo_sleep(philos);
	while (++eaten != philos->pdata->times_eat && !check_death(philos, 0))
	{
		philo_eat(philos);
		philo_sleep(philos);
	}
	return (NULL);
}

int	philo_start(t_pdata *pdata, int amount)
{
	int	i;

	i = -1;
	pdata->philo = ft_calloc(amount, sizeof(t_philos));
	pthread_mutex_init(&(pdata->print), NULL);
	pthread_mutex_init(&(pdata->check_death), NULL);
	if (pdata->philo == NULL)
		return (error_number(0));
	pthread_init(pdata, amount);
	if (DEBUG)
		print_forks(pdata, amount);
	i = -1;
	while (++i < amount)
		pthread_create(&pdata->philo[i].thread, NULL, \
			&philo_routine, &pdata->philo[i]);
	i = -1;
	while (++i < amount)
		pthread_join(pdata->philo[i].thread, NULL);
	return (0);
}
