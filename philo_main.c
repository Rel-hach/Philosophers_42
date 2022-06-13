/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:01:42 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/13 22:03:33 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_and_store_args(int ac, char **str, t_commun *data)
{
	if (ft_str_is_number(str))
	{
		data->nb_of_philos = ft_atoi(str[1]);
		data->time_to_die = ft_atoi(str[2]);
		data->time_to_eat = ft_atoi(str[3]);
		data->time_to_sleep = ft_atoi(str[4]);
		if (ac == 6)
			data->meals_should_be_eaten = ft_atoi(str[5]);
	}
	return (1);
}

int	ft_check_numbers_validity(t_commun *data)
{
	if (data->nb_of_philos < 1 || data->nb_of_philos > 200)
		return (0);
	else if (data->time_to_die < 60 || data->time_to_eat < 60)
		return (0);
	else if (data->time_to_sleep < 60)
		return (0);
	return (1);
}

void	ft_wait_and_stop_philos(t_philo *philo)
{
	while (1)
	{
		if (philo->finish_meals == 1)
			break ;
		if (time_now() - philo->lm_time > philo->p->time_to_die)
		{
			printf("%ld %d died\n", time_now(), philo->id);
			break ;
		}
		philo = philo->next;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	t_commun	data;
	t_philo		*philo;
	int			index;

	index = 0;
	if (ac >= 5 && ac <= 6)
	{
		if (!ft_check_and_store_args(ac, av, &data))
			ft_error_message("only numbers are accepted");
		if (!ft_check_numbers_validity(&data))
			ft_error_message("a number or more is invalid\n");
		philo = ft_create_list_table(&data);
		ft_lstlast(philo)->next = philo;
		pthread_mutex_init(&philo->p->writing, NULL);
		while (index < philo->p->nb_of_philos)
		{
			pthread_create(&philo->philo, NULL, ft_routine, (void *)philo);
			philo = philo->next;
			index++;
		}
		ft_wait_and_stop_philos(philo);
		ft_free_lst(philo);
	}
	return (0);
}
