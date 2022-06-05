/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:14:11 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/05 08:34:18 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_if_dead(t_philo *philo)
{
	if (ft_get_time() - philo->ptr->meal_time > philo->ptr->die_time)
	{
		philo->ptr->is_dead++;
		pthread_mutex_lock(&philo->ptr->mutex);
		printf("%ld %d is dead\n", (ft_get_time() - philo->ptr->timey), philo->id);
		pthread_mutex_unlock(&philo->ptr->mutex);
		exit (1);
	}
	return (1);
}