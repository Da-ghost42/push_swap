/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:16:14 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/08 14:35:41 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	delast(t_node **head)
{
	t_node	*tmp;

	if (*head == NULL)
		exit (0);
	else if ((*head)->next == NULL)
	{
		free (*head);
		*head = NULL;
	}
	else
	{
		tmp = *head;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		free (tmp->next);
		tmp->next = NULL;
	}
}

void	ft_clear(t_node **a)
{
	int	i;
	int	j;

	i = 0;
	if (!*a)
		return ;
	j = lst_size(*a) - 1;
	while (*a && i++ <= j)
		delast(a);
}

void	ft_clean_error(t_node **a)
{
	ft_putstr_fd("Error", 2);
	ft_clear(a);
	exit (0);
}
