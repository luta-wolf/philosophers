/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/04/22 17:33:46 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//(!(ac == 5 || ac == 6))
int	parser(int ac, char **av)
{
	// pthread_t thread[4];
	// pthread_t *thrd;
	// thrd = malloc(pthread_t * argv[1]);
	// pthread_mutex_t forks[4];
	// t_philosopher filosophers[4];
	(void) av;
	if (ac != 5 && ac != 6)
	{
		printf("Wrong number of arguments:  argc = %d\n", ac);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (parser(argc, argv))
		return (1);
	return (0);
}
