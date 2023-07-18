/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:26:13 by mboutuil          #+#    #+#             */
/*   Updated: 2022/11/11 22:16:58 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ndst;
	char	*nsrc;

	ndst = (char *)dst;
	nsrc = (char *)src;
	if (dst <= src)
		return (ft_memcpy(ndst, nsrc, len));
	if (dst > src)
		while (len--)
			ndst[len] = nsrc[len];
	return (dst);
}
