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

typedef struct s_philos
{
	int				id;
	long int		last_eaten;
	int				times_eaten;
	pthread_t		thread;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	fork_r;
}	t_philos;

typedef struct s_pdata
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_eat;
	int				has_died;
	long int		init;
	pthread_t		main;
	pthread_mutex_t	print;
	t_philos		*philo;
}	t_pdata;

// --- PHILOSOPHERS --- //

void	*philo_routine(void *p);
int		get_timestamp(t_pdata *pdata, int mode);
int		minisleep(int time, t_pdata *pdata);
int		philo_actions(int time, int number, int mode);
int		philo_start(t_pdata *pdata, int amount);

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
