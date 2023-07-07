/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:45:04 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/07 00:59:01 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	push_he(t_node **a, t_node **b, int chunck, int size_chunck)
{
	if ((*a)->pos <= chunck - (size_chunck / 2))
		push(a, b, 1);
	else
	{
		push(a, b, 1);
		rotate(b, 1);
	}
}

void	sort_two(t_node **a)
{
	if ((*a)->x < (*a)->next->x)
		return ;
	else
		swap(a, 0);
}

void	first_big(t_node **a)
{
	if ((*a)->next->x < (*a)->next->next->x)
		rotate(a, 0);
	else if ((*a)->next->x > (*a)->next->next->x)
	{
		rotate(a, 0);
		swap(a, 0);
	}
}

void	mid_big(t_node **a)
{
	if ((*a)->x > (*a)->next->next->x)
	{
		rotate(a, 0);
		rotate(a, 0);
	}
	else if ((*a)->x < (*a)->next->next->x)
	{
		swap(a, 0);
		rotate(a, 0);
	}
}

void	sort_three(t_node **a)
{
	if ((*a)->x < (*a)->next->next->x && (*a)->next->x < (*a)->next->next->x)
		sort_two(a);
	if ((*a)->x > (*a)->next->x && (*a)->x > (*a)->next->next->x)
		first_big(a);
	if ((*a)->x < (*a)->next->x && (*a)->next->x > (*a)->next->next->x)
		mid_big(a);
}
