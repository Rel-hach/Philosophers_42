/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:54:21 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/05 03:31:26 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	ptr;

	gettimeofday(&ptr, NULL);
	return ((ptr.tv_sec * 1000) + (ptr.tv_usec / 1000));
}
