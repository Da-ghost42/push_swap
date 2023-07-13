/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:51:25 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/12 03:47:31 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	swap(t_node **a, int i)
{
	t_node	*tmp;

	if (a == NULL || lst_size(*a) == 1)
		return ;
	tmp = *a;
	*a = (*a)->next->next;
	tmp->next->next = NULL;
	add_front (a, tmp->x, tmp->pos);
	add_front (a, tmp->next->x, tmp->next->pos);
	ft_clear(&tmp);
	if (i == 0)
		write (1, "sa\n", 3);
	else if (i == 1)
		write (1, "sb\n", 3);
}

void	swap_swap(t_node **a, t_node **b, int i)
{
	swap (a, 3);
	swap (b, 3);
	if (i == 0)
		write (1, "ss\n", 3);
	else
		return ;
}

void	rotate(t_node **a, int i)
{
	t_node	*tmp;

	if (a == NULL || lst_size(*a) == 1)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	addback (a, tmp->x, tmp->pos);
	ft_clear (&tmp);
	if (i == 0)
		write (1, "ra\n", 3);
	else if (i == 1)
		write (1, "rb\n", 3);
	else
		return ;
}

void	re_rotate(t_node **a, t_node **b, int i)
{
	rotate (a, 3);
	rotate (b, 3);
	if (i == 0)
		write (1, "rr\n", 3);
	else
		return ;
}

void	rev_rotate(t_node **a, int i)
{
	t_node	*tmp;

	if (a == NULL || lst_size(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	add_front (a, tmp->next->x, tmp->next->pos);
	delast(&tmp);
	if (i == 0)
		write (1, "rra\n", 4);
	else if (i == 1)
		write (1, "rrb\n", 4);
}
