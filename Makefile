# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 21:53:08 by tponutha          #+#    #+#              #
#    Updated: 2024/01/15 06:01:18 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME		= minirt

# Compiler Porperties
CC			= cc
CFLAG		= -Wall -Werror -Wextra
CFLAG_DEBUG	= -g -fsanitize=address,undefined
RM			= rm -f

# Source Code
# MLX Source
MLX_PATH		= ./mlx/
MLX_LIB			= libmlx42.a
MLX_BUILD_PATH	= $(addprefix $(MLX_PATH), build)
MLX_LIB_PATH	= $(addprefix $(MLX_BUILD_PATH), $(MLX_LIB))

# Libft Source
LIBFT_PATH		= ./libft/
LIBFT_LIB		= libft.a
LIBFT_LIB_PATH	= $(addprefix $(LIBFT_PATH), $(LIBFT_LIB))

# Main Source
MAIN_PATH		= ./
MAIN_HEADER		= minirt.h
MAIN_SRC		= minirt.c
MAIN_SRCS		= $(addprefix $(MAIN_PATH), $(MAIN_SRC))
MAIN_HEADERS	= $(addprefix $(MAIN_PATH), $(MAIN_HEADER))
MAIN_OBJS		= $(MAIN_SRCS:.c=.o)

# Parser Source
PARSER_PATH		= ./parser/
PARSER_HEADER	= parser.h
PARSER_SRC		= readfile.c \
					utils.c
PARSER_SRCS		= $(addprefix $(PARSER_PATH), $(PARSER_SRC))
PARSER_HEADERS	= $(addprefix $(PARSER_PATH), $(PARSER_HEADER))
PARSER_OBJS		= $(PARSER_SRCS:.c=.o)

# Mandatory Objects
MANDATORY_OBJS		= $(MAIN_OBJS) $(PARSER_OBJS)
MANDATORY_HEADER	= $(MAIN_HEADERS) $(PARSER_HEADERS)

# Compile Object Files (Exclude library)
%.o: %.c $(MANDATORY_HEADER) Makefile
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

MLX_FLAG		= -L$(MLX_BUILD_PATH) -lmlx42
LIBFT_FLAG		= -L.$(LIBFT_PATH) -lft

# Main Rules
all:	$(NAME)

$(NAME):	$(MANDATORY_OBJS) mlx libft
	$(CC) $(CFLAG) $(MANDATORY_OBJS) $(MLX_FLAG) $(LIBFT_FLAG) -o $(NAME)

clean:
	$(RM) $(MANDATORY_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

mlx:
	cmake -S $(MLX_PATH) -B $(MLX_BUILD_PATH)
	cmake --build $(MLX_BUILD_PATH) -j4

mlx_clean:
	$(RM) -r $(MLX_BUILD_PATH)

mlx_re:	mlx_clean mlx

libft:
	make -C $(LIBFT_PATH)

libft_clean:
	make -C $(LIBFT_PATH)

libft_fclean:
	make -C $(LIBFT_PATH)

libft_re:	libft_fclean libft

# ETC Rules
norm:
	@norminette -R CheckForbiddenSourceHeader $(MAN_SRCS) $(MAN_HEADER) $(LIBFT_DIR)

.PHONY:	all clean fclean re mlx