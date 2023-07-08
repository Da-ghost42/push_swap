SRC = list_tools.c push_swap.c instru.c sort.c sort_four.c position.c sort_max.c ft_atoi.c clear.c 

SRC_B = get_next_line/get_next_line.c ft_atoi.c list_tools.c clear.c \
	get_next_line/get_next_line_utils.c bonus/instructions.c bonus/parsing.c bonus/checker.c 

OBJ_B = ${SRC_B:.c=.o}

OBJ = ${SRC:.c=.o}

HEADER = pushswap.h

NAME = push_swap

BONUS = checker

LIB = lib/libft.a

RM = rm -rf

CC = cc

OPTION_FLAG = -fsanitize=address

CFALGS = -Wall -Wextra -Werror

all:make_libft ${NAME}

bonus: make_libft ${BONUS}

${NAME}: ${OBJ}
	@echo "compiled"
	@${CC} ${CFALGS} ${OPTION_FLAG} ${OBJ} ${LIB} -o ${NAME}

${BONUS} : ${OBJ_B}
	@echo "compiled"
	@${CC} ${CFALGS} ${OPTION_FLAG} ${OBJ_B} ${LIB} -o ${BONUS}

%.o:%.c ${HEADER}
	@${CC} ${CFALGS} ${OPTION_FLAG} -c $< -o $@

make_libft : 
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
