/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/14 16:27:17 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_is_near(void *tmp)
{
	t_table		*all;
	t_philo		*p;
	int			i;

	all = tmp;
	p = all->philo;
	while (1)
	{
		i = -1;
		while (++i < all->count_philo)
		{
			if (all->count_of_lunch)
				if (p->count_eat == all->count_of_lunch)
					return (NULL);
			if (get_timestamp() - p[i].last_eat > p[i].time_to_die)
			{
				all->flag_of_death = 1;
				pthread_mutex_lock(&all->print);
				printf("%lld %d" YEL " is died"RESET"\n",
					get_timestamp() - p->time_start, p->id);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	*start_game(void *tmp)
{
	t_philo		*philo;
	t_table		*table;

	philo = (t_philo *)tmp;
	table = philo->arg;
	if (philo->id % 2 == 0)
	{
		philo_print(table, philo, "is thinking");
		usleep(50);
	}
	while (!table->flag_of_death)
	{
		if (table->count_of_lunch)
			if (philo->count_eat == table->count_of_lunch)
				return (NULL);
		if (philo_eating(table, philo))
			return (NULL);
		philo_sleeping(table, philo);
		philo_thinking(table, philo);
	}
	return (NULL);
}

int	philo_life(t_table *all)
{
	int			i;
	pthread_t	check;

	i = -1;
	all->time_start = get_timestamp();
	while (++i < all->count_philo)
	{
		all->philo[i].time_start = all->time_start;
		all->philo[i].last_eat = all->time_start;
	}
	i = -1;
	while (++i < all->count_philo)
		pthread_create(&all->thread[i], NULL, &start_game, &all->philo[i]);
	pthread_create(&check, NULL, &death_is_near, all);
	pthread_mutex_unlock(&all->print);
	pthread_join(check, NULL);
	i = -1;
	while (++i < all->count_philo)
		pthread_join(all->thread[i], NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	*all;

	if (check_arg(argc, argv))
		return (1);
	all = init_table(argc, argv);
	if (!all)
		return (ft_free(all));
	if (malloc_time(all))
		return (ft_free(all));
	if (init_philo(all))
		return (ft_free(all));
	philo_life(all);
	ft_destroy_mutex(all);
	ft_free(all);
	return (0);
}
