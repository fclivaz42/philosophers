/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:52:31 by fclivaz           #+#    #+#             */
/*   Updated: 2023/05/02 16:52:42 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_strlen(const char *s)
{
	int		x;

	x = 0;
	while (s[x] != 0)
		++x;
	return (x);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	int		len;
	int		x;

	x = -1;
	len = size * count;
	str = (char *)malloc(len);
	if (str == NULL)
		return (str);
	while (++x != len)
		str[x] = 0;
	return ((void *)str);
}

static long long int	ft_base_atoi(const char *nptr)
{
	long long int	x;
	long long int	neg;
	long long int	nbr;

	neg = 1;
	nbr = 0;
	x = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32)
		++x;
	if (nptr[x] == '-')
		neg = neg * -1;
	if (nptr[x] == '-' || nptr[x] == '+')
		++x;
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		nbr = (nbr * 10) + (nptr[x] - '0');
		++x;
	}
	return (nbr * neg);
}

static int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int				x;
	long long int	y;

	x = -1;
	while (nptr[++x] != 0)
		if (!(ft_isdigit(nptr[x])))
			return (-5);
	x = ft_base_atoi(nptr);
	y = ft_base_atoi(nptr);
	if (x != y)
		return (-5);
	return (x);
}
