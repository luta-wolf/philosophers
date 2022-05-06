/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/07 00:48:46 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_game(void *tmp)
{
	t_philo		*philo;

	philo = (t_philo *)tmp;
	while (philo->count_eat < philo->arg->count_of_lunch)
	{
		printf("philo %d %d\n", philo->id, philo->count_eat);
		philo->count_eat++;
	}

	return NULL;
}

int	philo_life(t_table *all)
{
	int i;

	i = 0;
	while (i < all->count_philo)
	{
		pthread_create(&all->thread[i], NULL, &start_game, &all->philo[i]);
		i++;
	}
	i = 0;
	while (i < all->count_philo)
	{
		pthread_join(all->thread[i], NULL);
		i++;
	}
	return 0;
}

void	ft_printf(t_table *all)
{
	printf("count_philo = %d\n", all->count_philo);
	printf("time_die = %d\n", all->time_to_die);
	printf("time_eat = %d\n", all->time_to_eat);
	printf("time_sleep = %d\n", all->time_to_sleep);
	printf("count_must_eat = %d\n", all->count_of_lunch);
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
	// for (int i = 0; i < all->count_philo; i++)
	// 	printf("[%p] %3d [%p] [%p]\n",
	// 		all->philo[i].arg, all->philo[i].id,
	// 			&all->philo[i].arg->fork[all->philo[i].right_fork],
	// 			&all->philo[i].arg->fork[all->philo[i].left_fork]);
	ft_destroy_mutex(all);
	ft_free(all);
	// ft_printf(all);
	return (0);
}
