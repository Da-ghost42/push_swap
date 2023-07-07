/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:04:33 by mboutuil          #+#    #+#             */
/*   Updated: 2022/11/13 02:49:34 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
