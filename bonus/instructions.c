/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:00:23 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/05 18:11:20 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bonus.h"

void	swap_c(t_node **a)
{
	int	x;
	int	pos;

	if (*a == NULL || lst_size (*a) == 1)
		error ();
	x = (*a)->x;
	pos = (*a)->pos;
	(*a)->x = (*a)->next->x;
	(*a)->pos = (*a)->next->pos;
	(*a)->next->x = x;
	(*a)->next->pos = pos;
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
		exit (0);
	}	
	tmp = *a;
	tmp = tmp->next;
	(*a)->next = NULL;
	addback (&tmp, (*a)->x, (*a)->pos);
	*a = tmp;
}

void	re_rotate_c(t_node **a, t_node **b)
{
	if (lst_size (*a) < 2 || lst_size (*b) < 2)
	{
		ft_putstr_fd ("KO", 1);
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
		exit (0);
	}
	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	add_front (a, tmp->next->x, tmp->next->pos);
	tmp->next = NULL;
}
