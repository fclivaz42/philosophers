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

void	*philo_routine(void *p)
{
	t_pdata	*pdata;

	pdata = (t_pdata *)p;
	return (NULL);
}

int	philo_start(t_pdata *pdata, int amount)
{
	int	i;

	i = -1;
	pdata->philo = ft_calloc(amount, sizeof(t_philos));
	if (pdata->philo == NULL)
		return(error_number(0));
	while (++i < amount)
	{
		pdata->philo[i].id = i + 1;
		pthread_mutex_init(&(pdata->philo[i].fork_r), NULL);
		if (i > 0)
			pdata->philo[i].fork_l = &pdata->philo[i - 1].fork_r;
		if (i == amount - 1)
			pdata->philo[0].fork_l = &pdata->philo[i].fork_r;
	}
	if (DEBUG)
	{
		i = -1;
		while (++i < amount)
		printf("Initialized Philo #%d.\t Fork L is %p, Fork R is %p.\n",
				pdata->philo[i].id, pdata->philo[i].fork_l,
				&pdata->philo[i].fork_r);
	}
	return (10);
}
