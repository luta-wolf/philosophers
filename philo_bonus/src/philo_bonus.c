/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:52:12 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/15 20:00:28 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*track_death(void *tmp)
{
	t_philo	*all;

	all = (t_philo *)tmp;
	while (1)
	{
		if (all->nbr_lunch)
			if (all->nbr_philo_eat == all->nbr_lunch)
				break ;
		if (get_timestamp() - all->time_last_eat > all->time_to_die)
		{
			all->flag_of_death = 1;
			sem_wait(all->sem_print);
			printf("%lld %d"YEL" is died"RESET"\n",
				get_timestamp() - all->time_start, all->name);
			break ;
		}
	}
	if (all->flag_of_death)
		exit (1);
	else
		exit (0);
}

int	philo_life(t_philo *all)
{
	if (pthread_create(&all->track_death, NULL, &track_death, all))
		return (print_error(6));
	if (all->name % 2 == 1)
		usleep(500);
	while (1)
	{
		if (all->nbr_lunch)
			if (all->nbr_philo_eat == all->nbr_lunch)
				break ;
		if (philo_eating(all))
			break ;
		philo_sleeping(all);
		philo_thinking(all);
	}
	if (pthread_join(all->track_death, NULL))
		return (print_error(7));
	return (0);
}

int	start_game(t_philo *all)
{
	int	i;
	int	status;

	i = -1;
	all->time_start = get_timestamp();
	while (++i < all->nbr_philo)
	{
		all->pid[i] = fork();
		if (all->pid[i] == -1)
			return (print_error(5));
		if (all->pid[i] == 0)
		{
			all->name = i + 1;
			all->time_last_eat = all->time_start;
			if (philo_life(all))
				return (0);
		}
	}
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WEXITSTATUS(status) == 1)
			return (ft_free(all), 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*all;

	if (check_arg(argc, argv))
		return (1);
	all = init_philo(argc, argv);
	if (init_sem_pid(all))
		return (1);
	if (start_game(all))
		return (1);
	ft_free(all);
	return (0);
}
