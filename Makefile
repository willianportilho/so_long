# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/07/21 04:27:37 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	change_map.c \
			check_input.c \
			check_map.c    \
			end_game.c      \
			errors.c         \
			ft_clear.c        \
			get_map.c          \
			init_vars.c         \
			so_long.c            \
			start_map.c           \
			utils.c

SOURCES_B =	animation_bonus.c \
			change_map_bonus.c \
			check_input_bonus.c \
			check_map_bonus.c    \
			end_game_bonus.c      \
			errors_bonus.c         \
			ft_clear_bonus.c        \
			get_map_bonus.c          \
			init_vars_bonus.c         \
			so_long_bonus.c            \
			start_map_bonus.c           \
			utils_bonus.c

NAME =		so_long
NAME_B =	so_long_bonus

CC =		cc
CFLAGS =	-g -Wall -Wextra -Werror
RM =		rm -f
RM_ALL =	rm -rf
MLX =		-lmlx -lXext -lX11

VAL =		valgrind --leak-check=full --show-leak-kinds=all

LIBFT =		./libft/libft.a

SRC_PATH =			src/
SRC_B_PATH =		src_bonus/

OBJ_PATH =			obj/
OBJ_B_PATH =		obj_bonus/

SRCS =		${addprefix ${SRC_PATH}, ${SOURCES}}
SRCS_B =	${addprefix ${SRC_B_PATH}, ${SOURCES_B}}

OBJS =		${addprefix ${OBJ_PATH}, ${SOURCES:.c=.o}}
OBJS_B =	${addprefix ${OBJ_B_PATH}, ${SOURCES_B:.c=.o}}

all:		${NAME}

${NAME}:	${LIBFT} ${OBJS}
			${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

${OBJ_PATH}%.o:	${SRC_PATH}%.c
				mkdir -p obj
				${CC} ${CFLAGS} -c $< -o $@

bonus:		${NAME_B}

${NAME_B}:	${LIBFT} ${OBJS_B}
			${CC} ${OBJS_B} ${LIBFT} ${MLX} -o ${NAME_B}

${OBJ_B_PATH}%.o:	${SRC_B_PATH}%.c
				mkdir -p obj_bonus
				${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:	
			@echo "compiling"
			make -C ./libft
			@echo "libft compiled"

clean:		
			${RM_ALL} ${OBJ_PATH}
			${RM_ALL} ${OBJ_B_PATH}
			make clean -C ./libft/

fclean:		clean
			${RM} ${NAME}
			${RM} ${NAME_B}
			make fclean -C ./libft/

re:			fclean all

rebonus:	fclean bonus

run:		${NAME}
			${VAL} ./${NAME} ber/map.ber

runbonus:	${NAME_B}
			${VAL} ./${NAME_B} ber/map_bonus.ber

.PHONY:		all bonus clean fclean re rebonus run runbonus

norm:
			norminette ${SRCS} ${SRCS_B}