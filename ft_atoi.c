/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:15:52 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/12 01:06:29 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	lst_size(t_node *x)
{
	t_node	*curr;
	int		i;

	curr = x;
	i = 0;
	if (x == NULL)
		return (0);
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void	push(t_node **a, t_node **b, int i)
{
	t_node	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	add_front (b, tmp->x, tmp->pos);
	delast(&tmp);
	if (i == 0)
		write (1, "pa\n", 3);
	else if (i == 1)
		write (1, "pb\n", 3);
	else
		return ;
}

int	ft_atoi(const char *str)
{
	int		s;
	int		n;

	s = 1;
	n = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '+' || *str == '-') && *(str + 1))
	{
		if (*str == '-')
				s *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (s < 0 && n > (n * 10) + (*str - '0'))
			error();
		else if (n > (n * 10) + (*str - '0'))
			error();
		n = (n * 10) + (*str - '0');
		str++;
	}
	if (*str)
		error();
	return (n * s);
}
