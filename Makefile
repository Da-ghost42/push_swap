SRC = list_tools.c push_swap.c instru.c sort.c sort_four.c position.c sort_max.c ft_atoi.c clear.c 

SRC_B = ${shell ls *c}

OBJ_B = ${SRC_B:.c=.o}

OBJ = ${SRC:.c=.o}

HEADER = pushswap.h

BONUS_H = bonus/bonus.h

NAME = push_swap

BONUS = checker

LIB = lib/libft.a

RM = rm -rf

CC = cc

CFALGS = -Wall -Wextra -Werror

all:make_libft ${NAME}

bonus: make_libft ${BONUS}

${NAME}: ${OBJ}
	@echo "compiled"
	@${CC} ${CFALGS} ${OBJ} ${LIB} -o ${NAME}

${BONUS} : ${OBJ_B} ${BONUS_H}
	@echo "compiled"
	@${CC} ${CFALGS} ${OBJ_B} ${LIB} -o ${BONUS}

%.o:%.c ${HEADER} ${BONUS_H}
	@${CC} ${CFALGS} -c $< -o $@

make_libft :
	@echo "lib compiled"
	@make -C lib
clean :
	@make clean -C lib
	@${RM} ${OBJ}

fclean :
	@echo "cleaned"
	@make fclean -C lib
	@${RM} ${NAME} ${OBJ} ${OBJ_B} ${BONUS}

re : fclean all

.PHONY : all clean fclean re make_libft

.SILENT : all clean fclean re
