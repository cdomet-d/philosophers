/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:16:05 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/06/03 18:00:54 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*phi;
	// pthread_t	tid;
	
	// tid = pthread_self();
	phi = (t_philo *)arg;
	fprintf(stderr, "🍴 I am philo %3d\n", phi->ph_id);
	// thread : %10ld\n
	// tid
	return (NULL);
}