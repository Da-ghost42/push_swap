/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 04:07:06 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/07 01:00:44 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sec_max(t_node *a)
{
	int	j;
	int	max;
	int	s_max;

	j = lst_size (a);
	max = a->x;
	s_max = a->x;
	if (j == 1)
		return (a->x);
	while (a)
	{
		if (a->x > max)
		{
			s_max = max;
			max = a->x;
		}
		else if (a->x > s_max && a->x < max)
			s_max = a->x;
		a = a->next;
	}
	return (s_max);
}

void sort_max(t_node **a, t_node **b, int num)
{
	int chunck;
	int i;
	int j;

	i = lst_size(*a);
	j = 0;
	position(a, i);
	int size_chunck = i / num;
	chunck = size_chunck + (i % num);
	while (*a && chunck <= i)
	{
		if (j == chunck)
			chunck += size_chunck;
		if ((*a)->pos <= chunck)
		{
			if ((*a)->pos <= chunck - (size_chunck / 2))
				push(a, b, 1);
			else
			{
				push(a, b, 1);
				rotate(b, 1);
			}
			j++;
		}
		else
			rotate(a, 0);
	}
	position(b,i);
	to_a(a, b, i - 1);
}

int	less_instra(t_node *b, int ind)
{
	int	size;

	size = lst_size(b);
	if (ind <= lst_size(b) / 2)
		return (ind);
	else
		return (size - ind + 1);
}

void	push_one(t_node **a, t_node **b, int pos)
{
	int	p;
	int	l;
	int	j;

	p = lst_size(*b);
	l = pos_finder(*b, pos);
	if (l <= p / 2)
	{
		while (l--)
			rotate(b, 1);
	}
	else
	{
		j = p - l + 1;
		while (--j)
			rev_rotate(b, 1);
	}
	push(b, a, 0);
}

void to_a(t_node **a, t_node **b, int pos)
{
	int swp;

	while ((*b))
	{
		swp = 0;
		if (less_instra(*b, pos_finder(*b, pos)) <= less_instra(*b,pos_finder(*b, pos - 1)))
		{
			norm_help(a,b,pos,0);
			pos -= 2;
		}
		else
		{
			if (lst_size(*b) >= 2)
			{
				norm_help(a,b,pos,1);
				pos -= 2;
				swp = 1;
			}
			else
				push_one(b, a, pos--);
		}
		if (swp == 1)
			swap(a, 0);
	}
}
