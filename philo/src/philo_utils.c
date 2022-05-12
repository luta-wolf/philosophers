/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:46:01 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/10 19:53:18 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
{
	int					i;
	int					flag;
	unsigned long long	nbr;

	i = 0;
	nbr = 0;
	flag = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (-1);
	if (flag == 1 && nbr >= 9223372036854775807u)
		return (-1);
	if (flag == -1 && nbr >= 9223372036854775808u)
		return (0);
	return (nbr * flag);
}

long long	get_timestamp(void)
{
	struct timeval	t;
	long long		now;

	gettimeofday (&t, NULL);
	now = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (now);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_timestamp();
	while (get_timestamp() - start < time)
		usleep(100);
}

int	ft_free(t_table *all)
{
	if (all->philo)
		free(all->philo);
	if (all->fork)
		free(all->fork);
	if (all->thread)
		free(all->thread);
	free(all);
	return (1);
}

void	ft_destroy_mutex(t_table *all)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(&all->print);
	while (i < all->count_philo)
		pthread_mutex_destroy(&all->fork[i++]);
	pthread_mutex_destroy(&all->print);
}
