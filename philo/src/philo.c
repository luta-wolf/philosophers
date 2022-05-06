/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/06 06:51:22 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_game(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while(1)
	{
		printf("(+)\n");
	}
}

void	philo_life(t_table *all)
{
	int i;

	i = 0;
	all->start = get_timestamp();
	while (i < all->count_philo)
	{
		if (all->philo->id % 2 == 0)
			ft_usleep(100);
		all->philo[i].last_eat = get_timestamp();
		// pthread_create(&all->thread[i], NULL, start_game, (void *)&all->philo[i]);
		i++;
	}

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
	ft_destroy_mutex(all);
	ft_free(all);
	ft_printf(all);
	return (0);
}
