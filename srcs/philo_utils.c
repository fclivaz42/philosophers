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
		if (usleep(1000) == -1)
			return (-1);
	return (0);
}

int	get_timestamp(t_philo *philo)
{
	struct timeval	time;
	struct timezone	tzone;
	long long int	ret;

	if (gettimeofday(&time, &tzone) == -1)
		return (-1);
	ret = (philo->timestamp - ((time.tv_sec * 1000000) + time.tv_usec));
	return (ret / 1000);
}

void	*philo_routine(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;

	return (NULL);
}
