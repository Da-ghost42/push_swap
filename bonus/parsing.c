/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:14:23 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/07 17:25:58 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

int	check_alpha(char **split)
{
	int	x;
	int	i;

	x = 0;
	while (split[x])
	{
		i = 0;
		while (split[x][i])
		{
			if (!ft_isdigit(split[x][i]))
			{
				if (split[x][i] != '+' && split[x][i] != '-')
					return (0);
			}
			i++;
		}
		x++;
	}
	return (1);
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
		error();
	split = ft_split(av, ' ');
	if (!*split)
		error ();
	if (!check_alpha(split))
		error();
	while (split[x])
	{
		y = ft_atoi(split[x]);
		if (list == NULL)
			list = lst_new(y);
		else
			addback(&list, y, 0);
		x++;
	}
	return (list);
}

t_node	*pars_args(int ac, char **av)
{
	t_node	*ptr;
	t_node	*parsed_list;
	int		i;
	t_node	*temp;

	i = 0;
	ptr = NULL;
	while (++i < ac)
	{
		parsed_list = pars_one(av[i]);
		if (parsed_list == NULL)
			error();
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

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;

	b = NULL;
	if (!*av || ac == 1)
		error();
	a = pars_args (ac, av);
	check_dup (a);
	check_sorted (a);
	i = lst_size(a);
	do_instru (&a, &b);
	print_ko(a, i);
}
