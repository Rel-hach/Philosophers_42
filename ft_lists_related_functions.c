/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_related_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:54:34 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/13 05:09:02 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(t_commun *data)
{
	static int	i;
	t_philo		*philo;

	++i;
	philo = (t_philo *)malloc (sizeof (t_philo));
	if (!philo)
		return (NULL);
	pthread_mutex_init((&philo->fork), NULL);
	philo->id = i;
	philo->p = data;
	philo->eaten_meals = 0;
	philo->lm_time = 0;
	philo->finish_meals = 0;
	philo->next = NULL;
	return (philo);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = *lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
}

t_philo	*ft_lstlast(t_philo *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_philo	*ft_create_list_table(t_commun *data)
{
	t_philo	*new;
	t_philo	*head;
	int		i;

	i = 0;
	if (data->nb_of_philos == 0)
		exit(0);
	head = ft_lstnew(data);
	i++;
	while (i < data->nb_of_philos)
	{
		new = ft_lstnew(data);
		ft_lstadd_back(&head, new);
		i++;
	}
	return (head);
}

void	ft_free_lst(t_philo *philo)
{
	int		i;
	t_philo	*temp;

	i = 0;
	temp = philo;
	while (i < philo->p->nb_of_philos)
	{
		temp = philo->next;
		free(philo);
		philo = temp;
		i++;
	}
}
