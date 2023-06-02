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
	int				last_eaten;
	int				times_eaten;
	int				*state_l;
	int				state_r;
	pthread_t		thread;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*check_state_l;
	pthread_mutex_t	fork_r;
	pthread_mutex_t	check_state_r;
	struct s_pdata	*pdata;
}	t_philos;

typedef struct s_pdata
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_eat;
	int				has_died;
	long int		init;
	pthread_mutex_t	check_death;
	pthread_mutex_t	print;
	t_philos		*philo;
}	t_pdata;

// --- PHILOSOPHERS --- //

void	*philo_routine(void *p);
void	lock_unlock_madness(t_philos *philos);
void	pthread_init(t_pdata *pdata, int amount);
int		philo_actions(t_philos *philos, int number, int mode);
int		get_timestamp(t_pdata *pdata, int mode);
int		check_death(t_philos *philos, int mode);
int		philo_start(t_pdata *pdata, int amount);
int		smartsleep(int time, t_philos *philos);
int		trylock(t_philos *philos, char side);

// --- WALMART LIBFT --- //

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t count, size_t size);

// --- BUNGIE SPECIFIC --- //

void	print_forks(t_pdata *pdata, int amount);
int		error_incorrect_use(void);
int		error_number(int mode);

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef EXTRAL
#  define EXTRAL 0
# endif

# ifndef EXTRAR
#  define EXTRAR 0
# endif

#endif
