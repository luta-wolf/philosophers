/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:08:50 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/15 13:28:13 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	ft_atoi(const char *str)
{
	int					i;
	int					flag;
	unsigned long long	nbr;

	i = 0;
	nbr = 0;
	flag = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (-1);
	if (flag == 1 && nbr >= 9223372036854775807u)
		return (-1);
	if (flag == -1 && nbr >= 9223372036854775808u)
		return (0);
	return (nbr * flag);
}

int	print_error(int code)
{
	printf(RED "Error: " RESET);
	if (code == 1)
		printf("wrong number of arguments.\n");
	else if (code == 2)
		printf("arguments are not correct.\n");
	else if (code == 3)
		printf("malloc allocation error.\n");
	else if (code == 4)
		printf("semafor creation error.\n");
	return (1);
}

void	ft_free(t_philo *all)
{
	sem_unlink("print");
	sem_unlink("fork");
	sem_close(all->sem_print);
	sem_close(all->sem_fork);
	free(all->pid);
	free(all);
}

