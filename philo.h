/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:33:37 by rel-hach          #+#    #+#             */
/*   Updated: 2022/06/12 23:50:55 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// used sturcts :

typedef struct s_commun
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_should_be_eaten;
	pthread_mutex_t	writing;
}		t_commun;

typedef struct s_philo
{
	int				id;
	int				eaten_meals;
	int				finish_meals;
	pthread_t		philo;
	pthread_mutex_t	fork;
	long			lm_time;
	struct s_commun	*p;
	struct s_philo	*next;
}	t_philo;

// utils :

void	ft_putstr_fd(char *str, int fd);
void	ft_error_message(char *str);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
int		ft_str_is_number(char **str);

// lists :

t_philo	*ft_lstnew(t_commun *data);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_free_lst(t_philo *philo);
t_philo	*ft_create_list_table(t_commun *data);

// time management :

long	time_now(void);
void	ft_usleep(long sleep_time);

// actions :

void	*ft_routine(void *arg);
void	ft_right_fork(t_philo *philo);
void	ft_left_fork(t_philo *philo);
void	ft_sleep_then_think(t_philo *philo);

#endif
