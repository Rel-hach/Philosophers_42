/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:54:21 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/08 05:33:37 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_now(void)
{
	static int		i;
	static time_t	first_process_time;
	static time_t	new_process_time;
	struct timeval	ptr;

	gettimeofday(&ptr, NULL);
	if (i++ == 0)
		first_process_time = ((ptr.tv_sec * 1000) + (ptr.tv_usec / 1000));
	new_process_time = (ptr.tv_sec * 1000) + (ptr.tv_usec / 1000);
	return (new_process_time - first_process_time);
}

void	ft_usleep(long sleep_time)
{
	long	t;

	t = time_now();
	while (time_now() < t + sleep_time)
		usleep(50);
}
