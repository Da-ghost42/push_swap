/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:40:54 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/07 16:26:28 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<limits.h>
# include"lib/libft.h"

typedef struct s_node
{
	int				x;
	int				pos;
	struct s_node	*next;
}	t_node;

void	ft_clear(t_node **a);
int		pos_finder(t_node *a, int v);
void	check_sorted(t_node *a);
void	push_he(t_node **a, t_node **b, int chunck, int size_chunck);
int		max_value(t_node *a);
int		max_one(t_node *a, int i);
void	push_help(t_node **a, t_node **b, int i);
void	sort_four(t_node **a, t_node **b);
int		min_list(t_node *a);
int		*sort_tab(int *p, int n);
void	to_a(t_node **a, t_node **b, int pos);
void	norm_help(t_node **a, t_node **b, int pos, int i);
void	position(t_node **a, int n);
void	sort_max(t_node **a, t_node **b, int num);
void	sort_five(t_node **a, t_node **b);
void	rotate(t_node **a, int i);
void	sort_two(t_node **a);
void	sort_three(t_node **a);
t_node	*lst_new(int content);
void	push(t_node **a, t_node **b, int i);
void	swap(t_node **a, int i);
int		lst_size(t_node *x);
void	rev_rotate(t_node **a, int i);
void	swap_swap(t_node **a, t_node **b, int i);
t_node	*add_end(t_node *ptr, int value);
void	addback(t_node **head, int value, int pos);
t_node	*add_font(t_node *head, int value);
void	add_front(t_node **head, int value, int pos);
void	error(void);
int		ft_atoi(const char *str);
void	push_two(t_node **a, t_node **b, int pos);
void	push_one(t_node **a, t_node **b, int pos);
void	re_rotate(t_node **a, t_node **b, int i);
char	*get_next_line(int fd);
void	check_instru(t_node **a, t_node **b);
void	ft_clean_error(t_node **a, t_node **b);

#endif