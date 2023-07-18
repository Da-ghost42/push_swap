/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:05:34 by mboutuil          #+#    #+#             */
/*   Updated: 2023/07/13 03:30:12 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		len_s1;
	int		len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlenght(s1);
	len_s2 = ft_strlenght(s2);
	p = (char *)malloc(len_s1 + len_s2 + 1);
	if (!p)
		return (NULL);
	ft_memcpy (p, s1, len_s1);
	ft_memcpy (p + len_s1, s2, len_s2);
	p[len_s1 + len_s2] = 0;
	return (p);
}

char	*read_func(int fd)
{
	int		count;
	char	*line;
	char	*tmp;
	char	*tmp2;

	line = NULL;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strfind(line, '\n'))
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count < 0)
			return (free(tmp), NULL);
		if (count == 0)
			break ;
		tmp[count] = 0;
		tmp2 = line;
		line = ft_strjoin(line, tmp);
		if (!line)
			return (free(tmp), free(tmp2), NULL);
		free(tmp2);
	}
	return (free(tmp), line);
}

char	*get_rest(char *hold)
{
	int		nl;
	int		i;
	char	*new_hold;

	nl = 0;
	i = 0;
	new_hold = NULL;
	while (hold[nl] && hold[nl] != '\n')
		nl++;
	if (hold[nl] && hold[nl + 1] && hold[nl] == '\n')
	{
		new_hold = malloc(ft_strlenght(hold) - nl + 1);
		if (!new_hold)
			return (NULL);
		while (hold[++nl])
			new_hold[i++] = hold[nl];
			new_hold[i] = 0;
	}
	return (new_hold);
}

char	*get_line(char *line)
{
	char	*str;
	int		nl;

	str = NULL;
	nl = 0;
	while (line && line[nl] && line[nl] != '\n')
		nl++;
	if (line && line[nl] == '\n')
	{
		str = malloc(nl + 2);
		if (!str)
			return (free(line), NULL);
		ft_memcpy(str, line, nl + 1);
		str[nl + 1] = 0;
	}
	return (free(line), str);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*tmp;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_func(fd);
	if (hold)
	{
		tmp = line;
		line = ft_strjoin(hold, line);
		free(tmp);
		free(hold);
		hold = NULL;
	}
	if (line && ft_strfind(line, '\n'))
	{
		if (ft_strlenght(line) > 1)
			hold = get_rest(line);
		line = get_line(line);
	}
	return (line);
}
