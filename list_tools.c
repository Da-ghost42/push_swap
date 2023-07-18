/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:41:02 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/18 08:42:26 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	error(void)
{
	ft_putendl_fd("ERROR", 2);
	exit (0);
}

void	check_sorted(t_node *a)
{
	t_node	*tmp;

	tmp = a;
	while (tmp->next && tmp->x < tmp->next->x)
			tmp = tmp->next;
	if (!tmp->next)
	{
		ft_clear(&a);
		exit (EXIT_FAILURE);
	}
}

t_node	*lst_new(int content)
{
	t_node	*ptr;

	ptr = malloc (sizeof(t_node));
	if (!ptr)
		exit (0);
	ptr->x = content;
	ptr->next = NULL;
	return (ptr);
}

void	add_front(t_node **head, int value, int pos)
{
	t_node	*tmp;

	tmp = malloc (sizeof(t_node));
	if (!tmp)
		ft_clean_error (head);
	tmp->x = value;
	tmp->pos = pos;
	tmp->next = NULL;
	tmp->next = *head;
	*head = tmp;
}

void	addback(t_node **head, int value, int pos)
{
	t_node	*ptr;
	t_node	*tmp;

	if (lst_size (*head) < 1)
		return ;
	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	tmp = malloc (sizeof(t_node));
	if (!tmp)
		ft_clean_error(head);
	tmp->x = value;
	tmp->pos = pos;
	tmp->next = NULL;
	ptr->next = tmp;
}
