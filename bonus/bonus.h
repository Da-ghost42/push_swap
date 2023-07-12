/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:56:44 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/12 01:44:38 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include<stdio.h>
# include<stdlib.h>
# include<limits.h>
# include "../pushswap.h"
# include"../lib/libft.h"

void	check_sorted(t_node *a);
void	print_ko(t_node *a, t_node *b,int i);
char	*get_next_line(int fd);
t_node	*lst_new(int content);
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
void	ft_do_instru(t_node **a, t_node **b, int flag);
t_node	*pars_one(char *av);

#endif