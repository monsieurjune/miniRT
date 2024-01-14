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

# Name of Program
NAME		= minirt

# Compiler Porperties
CC			= cc
CFLAG		= -Wall -Werror -Wextra -g -fsanitize=address,undefined
RM			= rm -f

# MLX Porperties
LIBFT_DIR	= ./libft
MLX_DIR		= ./mlx_apple
MLX_FLAG	= -framework OpenGL -framework AppKit
MLX			= make -C $(MLX_DIR)
LIBFT		= make -C $(LIBFT_DIR)
LIBFLAG		= -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lft -lm

# Main Code
MAIN_DIR		= ./
MAIN_HEADER		= minirt.h \
					keycode.h
MAIN_FILE		= minirt.c
MAIN_SRCS		= $(addprefix $(MAIN_DIR), $(MAIN_FILE))
MAIN_HEADERS	= $(addprefix $(MAIN_DIR), $(MAIN_HEADER))
MAIN_OBJS		= $(MAIN_SRCS:.c=.o)

# Parser Code
PARSER_DIR		= ./parser/
PARSER_HEADER	= parser.h
PARSER_FILE		= readfile.c \
					utils.c
PARSER_SRCS		= $(addprefix $(PARSER_DIR), $(PARSER_FILE))
PARSER_HEADERS	= $(addprefix $(PARSER_DIR), $(PARSER_HEADER))
PARSER_OBJS		= $(PARSER_SRCS:.c=.o)

# Source code
MAN_OBJS		= $(MAIN_OBJS) $(PARSER_OBJS)
MAN_HEADER		= $(MAIN_HEADERS) $(PARSER_HEADERS)

# Compile Object Files
%.o: %.c $(MAN_HEADERS) Makefile
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

# Main Rules
all:	$(NAME)

$(NAME):	$(MAN_OBJS)
	$(MLX)
	$(LIBFT)
	$(CC) $(CFLAG) $(MAN_OBJS) $(LIBFLAG) $(MLX_FLAG) -o $(NAME)

clean:
	$(MLX) clean
	$(LIBFT) clean
	$(RM) $(MAN_OBJS)

fclean:	clean
	$(LIBFT) fclean
	$(RM) $(NAME)

re:	fclean all

# ETC Rules
norm:
	@norminette -R CheckForbiddenSourceHeader $(MAN_SRCS) $(MAN_HEADER) $(LIBFT_DIR)

.PHONY:	all clean fclean re