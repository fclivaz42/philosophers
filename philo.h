/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:01:19 by fclivaz           #+#    #+#             */
/*   Updated: 2023/05/01 15:19:46 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	int				*times;
	int				times_eat;
	int				has_died;
	long long int	timestamp;
	pthread_t		main;
	pthread_t		*philos;
	pthread_mutex_t	*mutex;
}	t_philo;

// --- PHILOSOPHERS --- //

void	*philo_routine(void *p);
void	free_stuff(t_philo *philo);
int		get_timestamp(t_philo *philo);
int		minisleep(int time, t_philo *philo);
int		philo_actions(long int time, int number, int mode);

// --- WALMART LIBFT --- //

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

// --- BUNGIE SPECIFIC --- //

int		error_incorrect_use(void);
int		error_number(int mode);

# ifndef DEBUG
#  define DEBUG 0
# endif

#endif
