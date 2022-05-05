/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/05 07:37:53 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//(!(ac == 5 || ac == 6))
int	check_arg(int ac, char **av)
{
	// pthread_t thread[4];
	// pthread_t *thrd;
	// thrd = malloc(pthread_t * argv[1]);
	// pthread_mutex_t forks[4];
	// t_philosopher filosophers[4];
	// (void) av;
	if (ac != 5 && ac != 6)
	{
		printf(RED "Error: " RESET "Wrong number of arguments:  argc = %d\n", ac);
		return (1);
	}
	if(ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 ||
		ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0 ||
		(ac == 6 && ft_atoi(av[5]) <= 0))
	{
		printf(RED "Error: " RESET "Wrong arguments.\n");
		return (1);
	}
	return (0);
}

t_table	*init(int ac, char **av)
{
	t_table	*arg;

	arg = malloc(sizeof(t_table));
	if (!arg)
		return NULL;
	arg->count_philo = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	arg->count_of_lunch = 0;
	if (ac == 6)
		arg->count_of_lunch = ft_atoi(av[5]);
	return arg;
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
	all = init(argc, argv);
	ft_printf(all);

	return (0);
}
