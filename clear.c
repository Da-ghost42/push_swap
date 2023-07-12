/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:16:14 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/12 01:31:01 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free (str);
}

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
	if (!*a)
		return ;
	while (*a)
		delast(a);
}

void	ft_clean_error(t_node **a)
{
	ft_putstr_fd("Error", 2);
	ft_clear(a);
	exit (0);
}
