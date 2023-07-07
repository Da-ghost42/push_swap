/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:35:09 by mboutuil          #+#    #+#             */
/*   Updated: 2022/11/09 20:40:35 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	lsrc;
	size_t	i;

	lsrc = ft_strlen(src);
	if (len == 0)
		return (lsrc);
	i = 0;
	while (src[i] != '\0' && i < (len - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lsrc);
}
