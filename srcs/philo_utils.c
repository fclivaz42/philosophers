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

void	free_stuff(t_pdata *pdata)
{
	int	i;

	i = -1;
	while (&pdata->philo[++i] != NULL)
		free(&pdata->philo[i]);
}

int	minisleep(int time, t_pdata *pdata)
{
	while (--time != -1 && pdata->has_died != 1)
		if (usleep(1000) == -1)
			return (-1);
	return (0);
}

int	get_timestamp(t_pdata *pdata)
{
	struct timeval			time;
	unsigned long long int	ret;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	ret = (((time.tv_sec * 1000000) + time.tv_usec)- pdata->timestamp);
	return (ret / 1000);
}

void	*philo_routine(void *p)
{
	t_pdata *pdata;

	pdata = (t_pdata *)p;

	return (NULL);
}
