/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:39:20 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/04 22:55:08 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->ptr->mutex);
	printf("%ld %d is thinking\n", time, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
}

void	ft_sleep(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->ptr->mutex);
	time =  ft_get_time() - philo->ptr->begin_time;
	printf("%ld %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
	usleep(200);
}

void	ft_eat(t_philo *philo)
{
	long	time;

	time = ft_get_time ();
	if (philo->next == NULL)
		philo->next = philo->ptr->head;
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(&philo->ptr->mutex);
	philo->ptr->begin_time =  ft_get_time() - time;
	printf("%ld %d has taken forks\n", time, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
	pthread_mutex_lock(&philo->ptr->mutex);
	philo->ptr->begin_time =  ft_get_time() - philo->ptr->begin_time;
	printf("%ld %d is eating\n", time, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
	usleep(500);
	philo->ptr->meals_eaten++;
	if (philo->ptr->meals_eaten == philo->ptr->nb_meals)
		philo->ptr->is_full++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	*ft_philo_life_cycle(void *arg)
{
	t_philo	philo = *(t_philo *)arg;

	if (philo.id % 2 != 0)
		usleep(500);
	ft_eat(&philo);
	ft_sleep(&philo);
	ft_think(&philo);
	return (NULL);
}
