/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:39:20 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/05 08:30:30 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	long	timer;

	if (philo->ptr->is_dead == 0)
	{
		pthread_mutex_lock(&philo->ptr->mutex);
		timer =  ft_get_time() - philo->ptr->timey;
		printf("%ld %d is thinking\n", timer, philo->id);
		pthread_mutex_unlock(&philo->ptr->mutex);	
	}
}

void	ft_sleep(t_philo *philo)
{
	long	timer;
	if (philo->ptr->is_dead == 0)
	{
		pthread_mutex_lock(&philo->ptr->mutex);
		timer  =  ft_get_time() - philo->ptr->timey;
		printf("%ld %d is sleeping\n", timer, philo->id);
		pthread_mutex_unlock(&philo->ptr->mutex);
		usleep(20000);	
	}
}

void	ft_eat(t_philo *philo)
{
	long		current;
	t_philo		*left_fork;
	
	left_fork = philo->next;
	if (philo->next == NULL && philo->ptr->nb_philos > 1)
		left_fork = philo->ptr->head;
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->ptr->mutex);
	current =  ft_get_time() - philo->ptr->timey;
	printf("%ld %d has taken a fork\n", current, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
	pthread_mutex_lock(&left_fork->fork);
	pthread_mutex_lock(&philo->ptr->mutex);
	current =  ft_get_time() - philo->ptr->timey;
	printf("%ld %d has taken a fork\n", current, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
	pthread_mutex_lock(&philo->ptr->mutex);
	current =  ft_get_time() - philo->ptr->timey;
	philo->ptr->meal_time = ft_get_time();
	printf("%ld %d is eating\n", current, philo->id);
	pthread_mutex_unlock(&philo->ptr->mutex);
	usleep(500);
	philo->eaten++;
	if (philo->eaten == philo->ptr->nb_meals)
	{
		philo->full++;
		philo->eaten = 0;
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&left_fork->fork);
}

void	*ft_philo_life_cycle(void *arg)
{
	t_philo	philo = *(t_philo *)arg;

	if (philo.id % 2 != 0)
		usleep(500);
	while (philo.full != philo.ptr->nb_philos && philo.ptr->is_dead == 0)
	{
		ft_eat(&philo);
		ft_sleep(&philo);
		ft_think(&philo);
		if (ft_check_if_dead(&philo))
			exit(1);
	}
	if (philo.full == philo.ptr->nb_philos || philo.ptr->is_dead > 0)
		exit (0);
	return (NULL);
}
