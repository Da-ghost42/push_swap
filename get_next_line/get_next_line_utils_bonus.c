/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:08:44 by mboutuil          #+#    #+#             */
/*   Updated: 2023/02/02 14:14:28 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlenght(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strfind(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] && str[i] == c)
		return (i + 1);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p;
	char	*q;
	size_t	i;

	p = (char *)dst;
	q = (char *)src;
	if (p == q)
		return (p);
	i = 0;
	while (i < n)
	{
		*(p + i) = *(q + i);
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *todup)
{
	char	*str;
	size_t	n;

	n = ft_strlenght(todup);
	str = (char *)malloc(n + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, todup, n);
	str[n] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlenght(s) < start)
		len = 0;
	if ((size_t)ft_strlenght(s + start) < len)
		len = ft_strlenght(s + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_memcpy(sub, s + start, len);
	sub[len] = 0;
	return (sub);
}
