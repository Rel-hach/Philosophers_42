/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:55:19 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/13 23:57:28 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_right_fork(t_philo *philo)
{
	if (philo->finish_meals == 0)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->p->writing);
		printf("%ld %d has taken a fork\n", time_now(), philo->id);
		pthread_mutex_unlock(&philo->p->writing);
	}
}

void	ft_left_fork(t_philo *philo)
{
	if (philo->finish_meals == 0)
	{
		pthread_mutex_lock(&philo->next->fork);
		pthread_mutex_lock(&philo->p->writing);
		printf("%ld %d has taken a fork\n", time_now(), philo->id);
		pthread_mutex_unlock(&philo->p->writing);
	}
}

void	ft_sleep_then_think(t_philo *philo)
{
	if (philo->finish_meals == 0)
	{
		pthread_mutex_lock(&philo->p->writing);
		printf("%ld %d is sleeping\n", time_now(), philo->id);
		pthread_mutex_unlock(&philo->p->writing);
		ft_usleep(philo->p->time_to_sleep);
		pthread_mutex_lock(&philo->p->writing);
		printf("%ld %d is thinking\n", time_now(), philo->id);
		pthread_mutex_unlock(&philo->p->writing);
	}
}

int	ft_check_if_satisfied(t_philo *philo, int *satisfied)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	if (philo->eaten_meals == philo->p->meals_should_be_eaten)
		(*satisfied)++;
	if ((*satisfied) == philo->p->nb_of_philos)
	{
		tmp = philo;
		while (i < philo->p->nb_of_philos)
		{
			philo->finish_meals = 1;
			tmp = tmp->next;
			i++;
		}
		return (1);
	}
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo			*philo;
	static int		satisfied;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_usleep(10);
	while (philo)
	{
		ft_right_fork(philo);
		ft_left_fork(philo);
		philo->lm_time = time_now();
		pthread_mutex_lock(&philo->p->writing);
		printf("%ld %d is eating\n", time_now(), philo->id);
		pthread_mutex_unlock(&philo->p->writing);
		ft_usleep(philo->p->time_to_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		philo->eaten_meals++;
		if (ft_check_if_satisfied(philo, &satisfied))
			break ;
		if (philo->finish_meals != philo->p->nb_of_philos)
			ft_sleep_then_think(philo);
	}
	return (NULL);
}
