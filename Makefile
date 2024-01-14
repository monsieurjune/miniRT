# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 21:53:08 by tponutha          #+#    #+#              #
#    Updated: 2024/01/15 03:39:00 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of Program
NAME		= minirt

# Compiler Porperties
CC			= cc
CFLAG		= -Wall -Werror -Wextra# -g -fsanitize=address,undefined
RM			= rm -f

# MLX Porperties
LIBFT_DIR	= ./libft
MLX_DIR		= ./mlx_apple
MLX_FLAG	= -framework OpenGL -framework AppKit
MLX			= make -C $(MLX_DIR)
LIBFT		= make -C $(LIBFT_DIR)
LIBFLAG		= -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lft

# Source Code
MAN_DIR		= ./
MAN_HEADER	= 
MAN_FILE	= 
MAN_SRCS	= $(addprefix $(MAN_DIR), $(MAN_FILE))
MAN_HEADERS	= $(addprefix $(MAN_DIR), $(MAN_HEADER))
MAN_OBJS	= $(MAN_SRCS:.c=.o)

# Compile Object Files
%.o: %.c $(MAN_HEADERS)
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