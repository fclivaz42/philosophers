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

static int	philo_loop(t_philo *philo)
{

	return (1);
}

static int	initiate_times(t_philo *philo, int ac, char **av)
{
	philo->times = (int *)ft_calloc(ac - 1, sizeof(int));
	if (philo->times == NULL)
		return (error_number(0));
	philo->times[0] = ft_atoi(av[2]);
	if (philo->times[0] == -5)
		return (error_number(2));
	philo->times[1] = ft_atoi(av[3]);
	if (philo->times[1] == -5)
		return (error_number(3));
	philo->times[2] = ft_atoi(av[4]);
	if (philo->times[2] == -5)
		return (error_number(4));
	if (ac == 6)
	{
		philo->times_eat = ft_atoi(av[5]);
		if (philo->times_eat == -5)
			return (error_number(5));
	}
	philo->has_died = 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	philo;
	int		r_value;

	r_value = 0;
	if (ac < 5 || ac > 6)
		return (error_incorrect_use());
	if (ac == 5)
		philo.times_eat = -1;
	if (initiate_times(&philo, ac, av) < 0)
		return (2);
	if (philo_loop(&philo) < 0)
		r_value = 3;
	//free_stuff(&philo);
	return (r_value);
}
