/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:00:23 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/12 01:24:00 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bonus.h"

void	swap_c(t_node **a)
{
	t_node *tmp;

	if (*a == NULL || lst_size (*a) == 1)
		error ();
	tmp = *a;
	*a = (*a)->next->next;
	tmp->next->next = NULL;
	add_front (a, tmp->x, tmp->pos);
	add_front (a, tmp->next->x, tmp->next->pos);
	ft_clear(&tmp);
}

void	swap_swap_c(t_node **a, t_node **b)
{
	if (lst_size (*a) < 2 || lst_size (*b) < 2)
	{
		ft_putstr_fd ("KO", 1);
		exit (0);
	}
	swap_c (a);
	swap_c (b);
}

void	rotate_c(t_node **a)
{
	t_node	*tmp;

	if (a == NULL || lst_size (*a) < 2)
	{
		ft_putstr_fd ("KO", 1);
		ft_clear(a);
		exit (0);
	}	
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = NULL;
	addback (a, tmp->x, tmp->pos);
	delast(&tmp);
}

void	re_rotate_c(t_node **a, t_node **b)
{
	if (lst_size (*a) < 2 || lst_size (*b) < 2)
	{
		ft_putstr_fd ("KO", 1);
		ft_clear(a);
		ft_clear(b);
		exit (0);
	}
	rotate_c (a);
	rotate_c (b);
}

void	rev_rotate_c(t_node **a)
{
	t_node	*tmp;

	if (a == NULL || lst_size (*a) < 2)
	{
		ft_putstr_fd ("KO", 1);
		ft_clear(a);
		exit (0);
	}
	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	add_front (a, tmp->next->x, tmp->next->pos);
	delast(&tmp);
}
