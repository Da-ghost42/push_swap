/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:56:44 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/06 03:22:18 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include<stdio.h>
# include<stdlib.h>
# include<limits.h>
# include"../lib/libft.h"

typedef struct s_node
{
	int				x;
	int				pos;
	struct s_node	*next;
}	t_node;

void	check_sorted(t_node *a);
char	*get_next_line(int fd);
t_node	*lst_new(int content);
void	print_ko(t_node *a, int i);
void	check_dup(t_node *head);
void	add_front(t_node **head, int value, int pos);
void	addback(t_node **head, int value, int pos);
int		lst_size(t_node *x);
void	check_instru(t_node **a, t_node **b, char *str);
t_node	*pars_args(int ac, char **av);
void	error(void);
void	rev_rotate_c(t_node **a);
void	re_rotate_c(t_node **a, t_node **b);
void	rotate_c(t_node **a);
void	swap_swap_c(t_node **a, t_node **b);
void	push_c(t_node **a, t_node **b);
void	swap_c(t_node **a);
int		ft_atoi(const char *str);
int		check_sort(t_node *a);
void	do_instru(t_node **a, t_node **b);
int		check_alpha(char **split);
t_node	*pars_one(char *av);

#endif