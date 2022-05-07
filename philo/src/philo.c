/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/07 08:09:24 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_game(void *tmp)
{
	t_philo		*philo;
	t_table		*table;

	philo = (t_philo *)tmp;
	table = philo->arg;
	if (philo->id % 2 == 0)
	{
		philo_print(table, philo, "is thinking");
		usleep(philo->time_to_eat);
	}
	while (!table->flag_of_death)
	{
		if (table->count_of_lunch)
			if (philo->count_eat == table->count_of_lunch)
				return (NULL);
		philo_eating(table, philo);
		philo_sleeping(table, philo);
		philo_thinking(table, philo);
	}
	return (NULL);
}

int	philo_life(t_table *all)
{
	int	i;

	i = -1;
	all->time_start = get_timestamp();
	while (++i < all->count_philo)
		all->philo[i].time_start = all->time_start;
	i = -1;
	while (++i < all->count_philo)
		pthread_create(&all->thread[i], NULL, &start_game, &all->philo[i]);
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
