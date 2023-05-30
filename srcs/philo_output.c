/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:29:05 by fclivaz           #+#    #+#             */
/*   Updated: 2023/05/01 15:29:14 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_forks(t_pdata *pdata, int amount)
{
	int	i;

	i = -1;
	while (++i < amount)
		printf("Initialized Philo #%d.\t Fork L is %p, Fork R is %p.\n",
			pdata->philo[i].id, pdata->philo[i].fork_l,
			&pdata->philo[i].fork_r);
}

int	error_incorrect_use(void)
{
	char	*a;
	char	*o;

	a = "\033[0;33mNumberOfPhilosophers TimeToDie TimeToEat TimeToSleep";
	o = "\033[0;32m[NumberOfTimesEachPhilosopherMustEat]";
	printf("\033[1;31mUsage:\n\033[1;33m./philo %s %s \033[0m\n", a, o);
	return (1);
}

int	error_number(int mode)
{
	printf("\033[1;31mError\033[0m: ");
	if (mode == 0)
		mode = printf("Failed to allocate memory.\n");
	if (mode == 1)
		printf("Incorrect amount of philosophers.\n");
	if (mode == 2)
		printf("Incorrect amount of time to 💀\n");
	if (mode == 3)
		printf("Incorrect amount of time to eat.\n");
	if (mode == 4)
		printf("Incorrect amount of time to sleep.\n");
	if (mode == 5)
		printf("Incorrect amount of necessary times to eat.\n");
	if (mode == 6)
		printf("Error getting time of day.\n");
	return (mode * -1);
}

int	philo_actions(t_philos *philos, int time, int number, int mode)
{
	pthread_mutex_lock(&philos->pdata->print);
	if (mode == 0)
		printf("%d\t : %d has taken a fork\n", time, number);
	if (mode == 1)
		printf("%d\t : %d is eating\n", time, number);
	if (mode == 2)
		printf("%d\t : %d is sleeping\n", time, number);
	if (mode == 3)
		printf("%d\t : %d is thinking\n", time, number);
	if (mode == 4)
		printf("%d\t : %d died 💀\n", time, number);
	pthread_mutex_unlock(&philos->pdata->print);
	return (0);
}
