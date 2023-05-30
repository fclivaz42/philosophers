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

static void	philo_eat(t_philos *philos)
{
	(void)philos;
	printf("philosopher %d eating\n", philos->id);
}

static void	philo_sleep(t_philos *philos)
{
	philo_actions(philos, get_timestamp(philos->pdata, 0), philos->id, 2);
	minisleep(philos->pdata->time_sleep, philos);
	if (philos->pdata->has_died == 1)
		return ;
	philo_actions(philos, get_timestamp(philos->pdata, 0), philos->id, 3);
}	

void	*philo_routine(void *p)
{
	t_philos	*philos;

	philos = (t_philos *)p;
	if (philos->id % 2 == 0)
		philo_sleep(philos);
	philo_eat(philos);
	return (NULL);
}

int	philo_start(t_pdata *pdata, int amount)
{
	int	i;

	i = -1;
	pdata->philo = ft_calloc(amount, sizeof(t_philos));
	pthread_mutex_init(&(pdata->print), NULL);
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
