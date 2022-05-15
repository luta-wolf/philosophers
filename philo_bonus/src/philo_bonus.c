/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:52:12 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/15 13:25:33 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	*all;

	if (check_arg(argc, argv))
		return (1);
	all = init_table(argc, argv);
	if (init_sem_pid(all))
		return (1);
	// start_game(all);
	ft_free(all);
	return (0);
}
