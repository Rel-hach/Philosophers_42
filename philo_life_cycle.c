/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:39:20 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/05 06:35:36 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	long	timer;

	pthread_mutex_lock(&philo->ptr->mutex);
	timer = philo->ptr->begin_time =  ft_get_time() - philo->ptr->timey;
	printf("%ld %d is thinking\n", timer, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
}

void	ft_sleep(t_philo *philo)
{
	long	timer;

	pthread_mutex_lock(&philo->ptr->mutex);
	timer = philo->ptr->begin_time =  ft_get_time() - philo->ptr->timey;
	printf("%ld %d is sleeping\n", timer, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
	usleep(20000);
}

void	ft_eat(t_philo *philo)
{
	long			current;
	t_philo	*left_fork;
	
	left_fork = philo->next;
	if (philo->next == NULL)
		left_fork = philo->ptr->head;
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&left_fork->fork);
	pthread_mutex_lock(&philo->ptr->mutex);
	current =  ft_get_time() - philo->ptr->timey;
	printf("%ld %d has taken forks\n", current, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
	pthread_mutex_lock(&philo->ptr->mutex);
	current =  ft_get_time() - philo->ptr->timey;
	philo->ptr->meal_time = ft_get_time();
	printf("%ld %d is eating\n", current, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
	usleep(500);
	philo->ptr->meals_eaten++;
	if (philo->ptr->meals_eaten == philo->ptr->nb_meals)
		philo->ptr->is_full++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&left_fork->fork);
}

void	*ft_philo_life_cycle(void *arg)
{
	t_philo	philo = *(t_philo *)arg;

	if (philo.id % 2 != 0)
		usleep(500);
	while (philo.ptr->is_full != philo.ptr->nb_philos)
	{
		ft_eat(&philo);
		ft_sleep(&philo);
		ft_think(&philo);
	}
	return (NULL);
}
