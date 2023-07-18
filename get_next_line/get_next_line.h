/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:15:34 by mboutuil          #+#    #+#             */
/*   Updated: 2023/02/02 00:27:54 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	24
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int		ft_strfind(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *todup);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlenght(char *str);
char	*get_next_line(int fd);

#endif