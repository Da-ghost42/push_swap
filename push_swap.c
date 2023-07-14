/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:39:10 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/14 10:54:56 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	norm_help(t_node **a, t_node **b, int pos, int i)
{
	if (i == 1)
	{
		if ((*b)->next)
			push_one(a, b, pos);
		push_one(a, b, pos - 1);
	}
	else
	{
		push_one(a, b, pos - 1);
		push_one(a, b, pos);
	}
}

void	check_dup(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->x == tmp->x)
				error();
			tmp = tmp->next;
		}
		head = head->next;
	}
}

t_node	*pars_one(char *av)
{
	char	**split;
	int		x;
	int		y;
	t_node	*list;

	x = 0;
	list = NULL;
	if (!*av)
		error ();
	split = ft_split(av, ' ');
	if (!*split)
		error ();
	while (split[x])
	{
		y = ft_atoi (split[x]);
		if (list == NULL)
			list = lst_new (y);
		else
			addback (&list, y, 0);
		x++;
	}
	ft_free(split);
	return (list);
}

t_node	*pars_args(int ac, char **av)
{
	t_node	*ptr;
	t_node	*parsed_list;
	t_node	*temp;
	int		i;

	i = 1;
	ptr = NULL;
	if (ac < 2)
		exit(EXIT_FAILURE);
	while (i++ < ac)
	{
		parsed_list = pars_one(av[i]);
		if (ptr == NULL)
		{
			ptr = parsed_list;
			temp = ptr;
		}
		else
		{
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = parsed_list;
		}
	}
	return (ptr);
}

void	leaks()
{
	system ("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_node	*head;
	t_node	*a;
	t_node	*b;

	b = NULL;
	atexit(leaks);
	if (!*av)
		error();
	head = pars_args(ac, av);
	a = head;
	check_dup(head);
	check_sorted(head);
	position(&a, lst_size (a));
	if (lst_size(a) == 2)
		sort_two(&a);
	else if (lst_size(a) == 3)
		sort_three(&a);
	else if (lst_size(a) == 4)
		sort_four(&a, &b);
	else if (lst_size(a) == 5)
		sort_five(&a, &b);
	else if (lst_size(a) > 5 && lst_size(a) <= 100)
		sort_max(&a, &b, 5, lst_size(a));
	else if (lst_size(a) > 100)
		sort_max(&a, &b, 9, lst_size(a));
	ft_clear (&a);
}
