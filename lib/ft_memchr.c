/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:26:27 by mboutuil          #+#    #+#             */
/*   Updated: 2022/10/16 21:44:05 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	l;

	if (!n)
		return (NULL);
	l = (unsigned char)c;
	tmp = (unsigned char *)s;
	while ((*tmp != l && --n))
			tmp++;
	if (*tmp == l)
		return (tmp);
	return (NULL);
}
