# -----------------------------------Makefile------------------------------------
NAME	= push_swap.a

# -----------------------------------Sources-------------------------------------

HEADER	= push_s.h \
		/libft/includes/ft_printf.h\
		/libft/includes/libft.h

PUSH_SWAP_SRCS	=	actions.c\
				doubles.c\
				main.c\
				stack_init.c\
				utils.c\
				push_swap.c\
				pusher.c\
				stack.c\
				back.c\




PUSH_SWAP_SRC	= ${PUSH_SWAP_SRCS}

ALL_SRC		= ${PUSH_SWAP_SRC} 

OBJS	= ${ALL_SRC:.c=.o}

# -----------------------------------Compilation------------------------------------

FT_FOLDER = ./libft

FT = ${FT_FOLDER}/libft.a

CC		= gcc -fsanitize=address -g

FLAGS	= -Wall -Wextra -Werror

LIB		= ar -rc

RM		= rm -f

MAKE_FT = make -s -C ${FT_FOLDER}

# -----------------------------------Libraries--------------------------------------

INCLUDES = -I ./includes

# -----------------------------------Rules------------------------------------------

all: ${NAME}

${NAME}: ${FT} ${OBJS}
		${LIB} ${NAME} ${OBJS}

${FT}: 
		${MAKE_FT}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c ${INCLUDES} $< -o $@

re: fclean all

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
		${MAKE_FT} fclean

# -----------------------------------.phony--------------------------------------

.PHONY: all clean fclean re