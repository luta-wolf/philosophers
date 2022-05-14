/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:12:28 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/14 13:10:10 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_arg(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (print_error(1));
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0
		|| (ac == 6 && ft_atoi(av[5]) <= 0))
		return (print_error(2));
	return (0);
}

t_philo	*init_table(int ac, char **av)
{
	t_philo	*all;

	all = malloc(sizeof(t_philo));
	if (!all)
		return (NULL);
	all->nbr_philo = ft_atoi(av[1]);
	all->time_to_die = ft_atoi(av[2]);
	all->time_to_eat = ft_atoi(av[3]);
	all->time_to_sleep = ft_atoi(av[4]);
	all->nbr_lunch = 0;
	if (ac == 6)
		all->nbr_lunch = ft_atoi(av[5]);
	all->left_fork = 0;
	all->right_fork = 0;
	all->flag_of_death = 0;
	all->time_start = 0;
	all->time_last_eat = 0;
}
