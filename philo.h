/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:37:42 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/04 22:42:00 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_commun
{
	int				nb_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				nb_meals;
	int				is_dead;
	int				is_full;
	long			begin_time;
	int				dead_time;
	int				meals_eaten;
	pthread_mutex_t	mutex;
	struct s_philo	*head;
}		t_commun;

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	fork;
	int				id;
	t_commun		*ptr;
	struct s_philo	*next;
}			t_philo;

// FUNCTIONS :

void	ft_putstr_fd(char *str, int fd);
void	ft_error_message(char *str);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
long	ft_get_time(void);
void	ft_check_args(char **str);
t_philo	*ft_lstnew(t_commun *content);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	ft_eat(t_philo *philo);
void	*ft_philo_life_cycle(void *arg);

#endif