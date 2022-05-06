/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:03 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/06 05:17:11 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> // usleep, write
# include <stdio.h> // printf
# include <string.h> // memset
# include <stdlib.h> // malloc, free
# include <sys/time.h> // gettimeofday
# include <pthread.h> //pthread_create

# define RED    "\x1b[31m"
# define BLU    "\x1B[34m"
# define GRN    "\x1B[32m"
# define YEL    "\x1B[33m"
# define MAG    "\x1B[35m"
# define CYN    "\x1B[36m"
# define WHT    "\x1B[37m"
# define RESET  "\x1B[0m"

typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				left_fork;
	int				right_fork;
	size_t			last_eat;
	struct s_arg	*arg;
}		t_philo;

typedef struct s_table
{
	int				count_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_of_lunch;
	int				flag_of_death;
	size_t			start;
	pthread_t		*thread;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}		t_table;

// philo_utils.c
long long	ft_atoi(const char *str);
size_t		get_timestamp(void);
int			ft_usleep(size_t m_sec);
int			ft_free(t_table *all);
void		ft_destroy_mutex(t_table *all);

//philo_init.c
int			check_arg(int ac, char **av);
t_table		*init_table(int ac, char **av);
int			malloc_time(t_table *all);
int			init_philo(t_table *all);

#endif
