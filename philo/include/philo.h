/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:03 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/07 09:08:50 by einterdi         ###   ########.fr       */
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
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_eat;
	int				left_fork;
	int				right_fork;
	long long		time_start;
	long long		last_eat;
	struct s_table	*arg;
}		t_philo;

typedef struct s_table
{
	int				count_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_of_lunch;
	int				flag_of_death;
	long long		time_start;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo			*philo;
}		t_table;

// philo_utils.c
long long	ft_atoi(const char *str);
long long	get_timestamp(void);
long long	ft_usleep(long long m_sec);
int			ft_free(t_table *all);
void		ft_destroy_mutex(t_table *all);

//philo_init.c
int			check_arg(int ac, char **av);
t_table		*init_table(int ac, char **av);
int			malloc_time(t_table *all);
int			init_philo(t_table *all);

//philo_life.c
void		philo_print(t_table	*table, t_philo *philo, char *str);
void		philo_eating(t_table	*table, t_philo *philo);
void		philo_sleeping(t_table *table, t_philo *philo);
void		philo_thinking(t_table *table, t_philo *philo);

#endif
