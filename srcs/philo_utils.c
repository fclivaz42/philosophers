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

void	free_stuff(t_philo *philo)
{
	free(philo->times);
	free(philo->philos);
	free(philo->mutex);
	free(philo->main);
}

int	minisleep(int time, t_philo *philo)
{
	while (--time != -1 && philo->has_died != 1)
		usleep(1000);
}

void	*philo_routine(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;

	return (NULL);
}