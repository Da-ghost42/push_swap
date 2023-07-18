/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:04:10 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/06 03:20:23 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	pos_finder(t_node *a, int big_num)
{
	int	i;
	int	j;

	i = 0;
	j = lst_size(a) - 1;
	if (a->pos == big_num)
		return (0);
	while (a && a->pos != big_num && i++ < j)
		a = (a)->next;
	return (i);
}

int	min_list(t_node *a)
{
	int	i;

	i = (a)->x;
	while (a)
	{
		if (i > (a)->x)
			i = (a)->x;
		a = (a)->next;
	}
	return (i);
}

void	four_helper(t_node **a, t_node **b, int i)
{	
	if (i == 1)
	{
		push (a, b, 1);
		sort_three (a);
		push (b, a, 0);
	}
	else
	{
		push (a, b, 1);
		sort_four (a, b);
		push(b, a, 0);
	}
}

void	sort_four(t_node **a, t_node **b)
{
	int	i;

	i = min_list (*a);
	if (i == (*a)->x)
		four_helper (a, b, 1);
	if (i == (*a)->next->x)
	{
		swap (a, 0);
		four_helper (a, b, 1);
	}
	if (i == (*a)->next->next->x)
	{
		rotate (a, 0);
		rotate (a, 0);
		four_helper (a, b, 1);
	}
	if (i == (*a)->next->next->next->x)
	{
		rev_rotate (a, 0);
		four_helper (a, b, 1);
	}
}

void	sort_five(t_node **a, t_node **b)
{
	int	i;

	i = min_list (*a);
	if (i == (*a)->x)
		four_helper (a, b, 0);
	if (i == (*a)->next->x)
		swap (a, 0);
	if (i == (*a)->next->next->x)
	{
		rotate (a, 0);
		rotate (a, 0);
	}
	if (i == (*a)->next->next->next->x)
	{
		rev_rotate (a, 0);
		rev_rotate (a, 0);
	}
	if (i == (*a)->next->next->next->next->x)
		rev_rotate (a, 0);
	four_helper(a, b, 0);
}
