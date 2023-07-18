/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:08:12 by mboutuil          #+#    #+#             */
/*   Updated: 2022/11/12 02:16:58 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;
	size_t	j;

	lsrc = ft_strlen(src);
	i = 0;
	if (!dst && !n)
		return (lsrc);
	ldst = ft_strlen(dst);
	j = ldst;
	if (ldst >= n)
		return (n + lsrc);
	while (src[i] && j < n - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (ldst + lsrc);
}
