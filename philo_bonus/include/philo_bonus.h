/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:03 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/15 19:44:14 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free, exit
# include <unistd.h>	// usleep, write, fork
# include <signal.h>	// kill
# include <pthread.h>	// pthread_create
# include <sys/time.h>	// gettimeofday
# include <sys/wait.h>	// waitpid
# include <semaphore.h>	// sem_open, sem_close ... sem_unlink

# define RED	"\033[31m"		// обычный
# define RED_B	"\033[1;31m"	// жирный
# define GRN	"\x1B[32m"		// обычный
# define GRN_B	"\x1B[1;32m"	// жирный
# define BLU	"\x1B[34m"
# define YEL	"\x1B[33m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"

typedef struct s_philo
{
	int			nbr_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_lunch;
	int			name;
	int			nbr_philo_eat;
	int			flag_of_death;
	long long	time_start;
	long long	time_last_eat;
	pid_t		*pid;
	pthread_t	track_death;
	sem_t		*sem_print;
	sem_t		*sem_fork;
}				t_philo;

//philo_bonus_init.c
int			check_arg(int ac, char **av);
t_philo		*init_philo(int ac, char **av);
int			small_free(t_philo *all, int code);
int			init_sem_pid(t_philo *all);

//philo_bonus_utils.c
long long	ft_atoi(const char *str);
long long	get_timestamp(void);
void		ft_usleep(long long time);
int			print_error(int code);
void		ft_free(t_philo *all);

// philo_bonus_life.c
void		philo_print(t_philo *all, char *str);
int			philo_eating(t_philo *all);
void		philo_sleeping(t_philo *all);
void		philo_thinking(t_philo *all);
#endif
