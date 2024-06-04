/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:05 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/06/04 14:20:02 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

# define ERROR 1
# define SUCCESS 0
# define INPUT_ERROR "Please enter in milliseconds :\n - number_of_philosophers\n - time_to_die\n - time_to_eat\n - time_to_sleep"

typedef struct s_fork {
	bool	fork;
	pthread_mutex_t	mfork;
} t_fork;
typedef struct s_param {
	time_t			start;
	ssize_t			n_philo;
	time_t			t_to_die;
	time_t			t_to_eat;
	time_t			t_to_sleep;
	ssize_t			n_must_eat;
	pthread_mutex_t	init_lock;
	bool		end;
} t_param;

typedef struct s_philo {
	pthread_t	tid;
	int			phid;
	t_fork		fork[2];
	size_t		nb_ate;
	time_t		last_ate;
	t_param		*param;
}	t_philo;

// utils ---------------------

/* display.c */
ssize_t	ft_putendl_fd(char *s, int fd);
ssize_t	ft_putl_fd(char *s, int fd);
void	dpm(t_param param);
void	dphi(t_philo phi);

/* error_management.c */
int	derr(char *err, char *param);

/* ft_atoi.c */

int	ft_atoi(char *nptr);

/* parsing.c */
int isnotdigit(char *str);
int	isdigit_param(char **args);

// src -----------------------

/* main.c */
int	main(int argc, char *argv[]);
int join_phi(t_philo *philo);

/* routine.c */
void	*routine(void *arg);

/* initialisation.c */
int	init_params(t_param	*param, char **args);
int	init_philo(t_param *param, t_philo *philo);

#endif