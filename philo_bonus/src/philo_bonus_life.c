/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:01:39 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/16 12:10:19 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_print(t_philo *all, char *str)
{
	sem_wait(all->sem_print);
	printf("%lld %d %s\n",
		get_timestamp() - all->time_start, all->name, str);
	sem_post(all->sem_print);
}

int	philo_eat_sleep_think(t_philo *all)
{
	sem_wait(all->sem_fork);
	philo_print(all, "has taken a fork");
	if (all->nbr_philo == 1)
		return (sem_post(all->sem_fork), 1);
	sem_wait(all->sem_fork);
	philo_print(all, "has taken a fork");
	philo_print(all, "is eating");
	all->time_last_eat = get_timestamp();
	ft_usleep(all->time_to_eat);
	sem_post(all->sem_fork);
	sem_post(all->sem_fork);
	all->nbr_philo_eat++;
	philo_print(all, "is sleeping");
	ft_usleep(all->time_to_sleep);
	philo_print(all, "is thinking");
	return (0);
}

int	killer(t_philo *all)
{
	int	i;

	i = -1;
	while (++i < all->nbr_philo)
		kill(all->pid[i], SIGKILL);
	return (0);
}
