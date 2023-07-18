# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 23:29:58 by mboutuil          #+#    #+#              #
#    Updated: 2023/07/06 21:14:08 by mboutuil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_isdigit.c ft_memset.c  ft_isprint.c ft_putendl_fd.c ft_itoa.c ft_strmapi.c \
		ft_bzero.c ft_putchar_fd.c ft_strncmp.c ft_memchr.c ft_striteri.c \
		ft_tolower.c  ft_strlen.c ft_putstr_fd.c ft_strlcat.c ft_calloc.c ft_strtrim.c \
		ft_toupper.c ft_isalnum.c ft_strrchr.c  ft_strlcpy.c ft_memcmp.c ft_split.c \
		ft_isalpha.c ft_memcpy.c ft_strchr.c  ft_putnbr_fd.c ft_strnstr.c ft_strjoin.c \
		ft_isascii.c ft_memmove.c ft_isascii.c ft_strchr.c ft_strdup.c ft_substr.c 

CC = cc

FLAGS = -Wall -Wextra -Werror -c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

RM = rm -f

all : ${NAME}

${NAME} : ${OBJS}
	@ar -rc $@ ${OBJS}

%.o : %.c libft.h
	@${CC} ${FLAGS} $< -o $@

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY : fclean clean re
