/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:29:05 by fclivaz           #+#    #+#             */
/*   Updated: 2023/05/01 15:29:14 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
		printf("Failed to allocate memory.\n");
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
	return (mode * -1);
}

int	philo_actions(long int time, int number, int mode)
{
	if (mode == 0)
		printf("%lu : %d has taken a fork\n", time, number);
	if (mode == 1)
		printf("%lu : %d is eating\n", time, number);
	if (mode == 2)
		printf("%lu : %d is sleeping\n", time, number);
	if (mode == 3)
		printf("%lu : %d is thinking\n", time, number);
	if (mode == 4)
		printf("%lu : %d died 💀\n", time, number);
	return (0);
}
