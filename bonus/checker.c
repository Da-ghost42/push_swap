/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:29:59 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/07 17:20:44 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	check_sort(t_node *a)
{
	while (a && a->next)
	{
		if (a->x < a->next->x)
			a = a->next;
		else
			return (1);
	}
	return (0);
}

void	print_ko(t_node *a, int i)
{
	if (!check_sort(a) && lst_size (a) == i)
	{
		ft_putstr_fd ("OK", 2);
		ft_clear(&a);
		return ;
	}
	else
	{
		ft_putstr_fd("KO", 2);
		ft_clear(&a);
		return ;
	}
}

void	check_instru(t_node **a, t_node **b, char *str)
{
	if (!ft_strncmp (str, "sa\n", 3))
		swap_c (a);
	else if (!ft_strncmp (str, "sb\n", 3))
		swap_c (b);
	else if (!ft_strncmp (str, "pa\n", 3))
		push_c (b, a);
	else if (!ft_strncmp (str, "pb\n", 3))
		push_c (a, b);
	else if (!ft_strncmp (str, "ss\n", 3))
		swap_swap_c (a, b);
	else if (!ft_strncmp (str, "ra\n", 3))
		rotate_c (a);
	else if (!ft_strncmp (str, "rb\n", 3))
		rotate_c (b);
	else if (!ft_strncmp (str, "rrb\n", 4))
		rev_rotate_c (b);
	else if (!ft_strncmp (str, "rra\n", 4))
		rev_rotate_c(a);
	else if (!ft_strncmp(str, "rr\n", 3))
		re_rotate_c (a, b);
	else
		error ();
}

void	do_instru(t_node **a, t_node **b)
{
	char	*str;

	str = get_next_line (0);
	while (str)
	{
		check_instru(a, b, str);
		free (str);
		str = get_next_line(0);
	}
}

void	push_c(t_node **a, t_node **b)
{
	t_node	*tmp;

	tmp = (*a)->next;
	(*a)->next = NULL;
	add_front(b, (*a)->x, (*a)->pos);
	*a = tmp;
}
