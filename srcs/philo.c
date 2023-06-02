/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:22:14 by fclivaz           #+#    #+#             */
/*   Updated: 2023/05/01 15:22:23 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	lock_unlock_madness(t_philos *philos)
{
	while (trylock(philos, 'R'))
		if (smartsleep(1, philos))
			return ;
	pthread_mutex_lock(&(philos->fork_r));
	pthread_mutex_lock(&philos->check_state_r);
	philos->state_r = 1;
	pthread_mutex_unlock(&philos->check_state_r);
	philo_actions(philos, philos->id, EXTRAR);
	while (trylock(philos, 'L'))
		if (smartsleep(1, philos))
			return ;
	pthread_mutex_lock(philos->fork_l);
	pthread_mutex_lock(philos->check_state_l);
	*philos->state_l = 1;
	pthread_mutex_unlock(philos->check_state_l);
	philo_actions(philos, philos->id, EXTRAL);
}

static void	freexit(t_pdata *pdata, int amt)
{
	int	i;

	i = -1;
	while (++i < amt)
	{
		pthread_mutex_destroy(pdata->philo[i].fork_l);
		pthread_mutex_destroy(pdata->philo[i].check_state_l);
		pthread_mutex_destroy(&pdata->philo[i].fork_r);
		pthread_mutex_destroy(&pdata->philo[i].check_state_r);
	}
	pthread_mutex_destroy(&pdata->print);
	pthread_mutex_destroy(&pdata->check_death);
	free(pdata->philo);
}

static int	philo_init(t_pdata *pdata, char *av)
{	
	int	amt;

	amt = ft_atoi(av);
	if (amt == -5)
		return (error_number(1));
	if (get_timestamp(pdata, 1) == -1)
		return (error_number(6));
	if (DEBUG)
		printf("Timestamp set to %ld!\n", pdata->init);
	philo_start(pdata, amt);
	freexit(pdata, amt);
	return (1);
}

static int	initiate_times(t_pdata *pdata, int ac, char **av)
{
	pdata->time_die = ft_atoi(av[2]);
	if (pdata->time_die == -5)
		return (error_number(2));
	pdata->time_eat = ft_atoi(av[3]);
	if (pdata->time_eat == -5)
		return (error_number(3));
	pdata->time_sleep = ft_atoi(av[4]);
	if (pdata->time_sleep == -5)
		return (error_number(4));
	if (ac == 6)
	{
		pdata->times_eat = ft_atoi(av[5]);
		if (pdata->times_eat == -5)
			return (error_number(5));
	}
	pdata->has_died = 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_pdata	pdata;
	int		r_value;

	r_value = 0;
	if (ac < 5 || ac > 6)
		return (error_incorrect_use());
	if (ac == 5)
		pdata.times_eat = -1;
	if (initiate_times(&pdata, ac, av) < 0)
		return (2);
	if (philo_init(&pdata, av[1]) < 0)
		r_value = 3;
	if (pdata.has_died == 0)
		printf("Simulation ended and no one died!! 😁😁\n");
	return (r_value);
}
