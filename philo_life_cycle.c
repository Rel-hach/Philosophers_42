/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:39:20 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/04 05:34:53 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	//pthread_mutex_lock(&philo->ptr->mutex);
	printf("philo %d is thinking\n", philo->id);
	//pthread_mutex_unlock(&philo->ptr->mutex);
}

void	ft_sleep(t_philo *philo)
{
	//pthread_mutex_lock(&philo->ptr->mutex);
	printf("philo %d is sleeping\n", philo->id);
	//pthread_mutex_unlock(&philo->ptr->mutex);
}

void	ft_eat(t_philo *philo)
{
	if (philo->next == NULL)
		philo->next = philo->ptr->head;
	//pthread_mutex_lock(&philo->ptr->mutex);
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
	printf("philo %d has taken forks\n", philo->id);
	printf("philo %d is eating\n", philo->id);
	usleep(10);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	//pthread_mutex_lock(&philo->ptr->mutex);
}

void	*ft_philo_life_cycle(void *arg)
{
	t_philo	philo = *(t_philo *)arg;

	if (philo.id % 2 == 0)
		usleep(500);
	ft_eat(&philo);
	ft_sleep(&philo);
	ft_think(&philo);
	return (NULL);
}