/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 05:30:13 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/07 09:14:49 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_table	*table, t_philo *philo, char *str)
{
	pthread_mutex_lock(&table->print);
	printf("[%7lld]ms philosopher [%3d] %s\n",
		get_timestamp() - philo->time_start, philo->id, str);
	pthread_mutex_unlock(&table->print);
}

void	philo_eating(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->fork[philo->left_fork]);
	philo_print(table, philo, "has taken a left  fork");
	pthread_mutex_lock(&table->fork[philo->right_fork]);
	philo_print(table, philo, "has taken a right fork");
	philo_print(table, philo, "is eating");
	philo->count_eat++;
	philo->last_eat = get_timestamp();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&table->fork[philo->left_fork]);
	pthread_mutex_unlock(&table->fork[philo->right_fork]);
}

void	philo_sleeping(t_table *table, t_philo *philo)
{
	philo_print(table, philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	philo_thinking(t_table *table, t_philo *philo)
{
	philo_print(table, philo, "is thinking");
}
