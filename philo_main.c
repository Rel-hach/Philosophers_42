/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:37:14 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/04 01:15:09 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_get_args(int ac, char **str, t_commun *data)
{
	data->nb_philos = ft_atoi(str[1]);
	data->die_time = ft_atoi(str[2]);
	data->eat_time = ft_atoi(str[3]);
	data->sleep_time = ft_atoi(str[4]);
	if (ac == 6)
		data->nb_meals = 0;
}

t_philo	*ft_create_list(t_commun *data)
{
	t_philo	*new;
	t_philo	*head;
	int		i;

	i = 1;
	head = ft_lstnew(data);
	while (i < data->nb_philos)
	{
		new = ft_lstnew(data);
		ft_lstadd_back(&head, new);
		i++;
	}
	return (head);
}

void	ft_create_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->ptr->nb_philos)
	{
		pthread_create(&philo->philo, NULL, )
	}
}

int	main (int ac, char **av)
{
	t_philo		*philo;
	t_commun	data;

	philo = NULL;
	if (ac != 5 && ac != 6)
		ft_error_message("The number of arguments is wrong");
	ft_check_args(av);
	ft_get_args(ac, av, &data);
	philo = ft_create_list(&data);
	ft_create_philos(&philo);
 }
