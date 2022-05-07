/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 02:23:41 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/07 06:58:35 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf(RED "Error: " RESET "Wrong number of arguments.\n");
		return (1);
	}
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0
		|| (ac == 6 && ft_atoi(av[5]) <= 0))
	{
		printf(RED "Error: " RESET "Wrong arguments.\n");
		return (1);
	}
	return (0);
}

t_table	*init_table(int ac, char **av)
{
	t_table	*arg;

	arg = malloc(sizeof(t_table));
	if (!arg)
		return (NULL);
	arg->count_philo = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	arg->count_of_lunch = 0;
	if (ac == 6)
		arg->count_of_lunch = ft_atoi(av[5]);
	arg->flag_of_death = 0;
	arg->time_start = 0;
	pthread_mutex_init(&arg->print, NULL);
	arg->thread = NULL;
	arg->philo = NULL;
	arg->fork = NULL;
	return (arg);
}

int	malloc_time(t_table *all)
{
	all->philo = malloc(sizeof(t_philo) * all->count_philo);
	if (!all->philo)
		return (1);
	all->fork = malloc(sizeof(pthread_mutex_t) * all->count_philo);
	if (!all->fork)
		return (1);
	all->thread = malloc(sizeof(pthread_t) * all->count_philo);
	if (!all->thread)
		return (1);
	return (0);
}

int	init_philo(t_table *all)
{
	int	i;

	i = 0;
	while (i < all->count_philo)
	{
		all->philo[i].id = i + 1;
		all->philo[i].time_to_die = all->time_to_die;
		all->philo[i].time_to_eat = all->time_to_eat;
		all->philo[i].time_to_sleep = all->time_to_sleep;
		all->philo[i].count_eat = 0;
		all->philo[i].left_fork = i;
		if (i < all->count_philo -1)
			all->philo[i].right_fork = i + 1;
		else
			all->philo[i].right_fork = 0;
		all->philo[i].last_eat = 0;
		all->philo[i].arg = all;
		i++;
	}
	i = 0;
	while (i < all->count_philo)
		if (pthread_mutex_init(&all->fork[i++], NULL))
			return (1);
	return (0);
}
