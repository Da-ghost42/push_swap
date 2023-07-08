/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:50:41 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/08 14:36:18 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	ft_do_instru(t_node **a, t_node **b, int flag)
{
	if (flag == 0)
		push (a, b, 1);
	else if (flag == 1)
	{
		push (a, b, 1);
		rotate (b, 1);
	}
	else
		rotate (a, 0);
}

int	*sort_tab(int *p, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i <= n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (p[j] > p[j + 1])
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		j++;
		}
	i++;
	}
	return (p);
}

void	do_pos(t_node **a, int *p)
{
	int		i;
	t_node	*tmp;

	tmp = *a;
	while (tmp)
	{
		i = -1;
		while (++i < lst_size (*a))
		{
			if (tmp->x == p[i])
				tmp->pos = i;
		}
		tmp = tmp->next;
	}
}

void	position(t_node **a, int n)
{
	int		i;
	int		*p;
	int		*ptr;
	t_node	*tmp;

	p = malloc(n * sizeof(int));
	if (!p)
		return ;
	tmp = *a;
	i = -1;
	while (tmp && ++i < n)
	{
		p[i] = tmp->x;
		tmp = tmp->next;
	}
	ptr = sort_tab (p, n);
	do_pos (a, ptr);
	free(p);
}
