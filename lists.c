/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:07:08 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/05 07:54:15 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(t_commun *content)
{
	static int	i;
	t_philo		*philo;

	++i;
	philo = (t_philo *)malloc (sizeof (t_philo));
	if (!philo)
		return (NULL);
	if (i == 1)
		content->head = philo;
	pthread_mutex_init((&philo->fork), NULL);
	philo->ptr = content;
	philo->eaten = 0;
	philo->full = 1;
	philo->id = i;
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
