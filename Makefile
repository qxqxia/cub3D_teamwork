# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 14:09:27 by qxia              #+#    #+#              #
#    Updated: 2022/09/05 13:57:09 by qxia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = clang

IFLAGS = -I./include -I./mlx -I./libft

LFLAGS = -L./libft -lft

CFLAG = -Wall -Wextra -Werror

MFLAGS = -L./mlx -lmlx -lXext -lX11 -lm

MLX_DIR := ./mlx

MLX = libmlx.a

SRCS := main.c \
			ft_return.c \
			ft_init_images.c \
			ft_free_cub3d.c \
			src/parser/check_map_util.c \
			src/parser/check_map.c \
			src/parser/ft_get_map.c \
			src/parser/ft_get_info.c \
			src/parser/parse_map.c \

OBJS := $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C ./libft
	@cp $(MLX_DIR)/$(MLX) .
	@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $@ $(LFLAGS) $(MFLAGS)

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(MLX)
	@$(MAKE) -C ./libft clean

fclean: clean
	@$(MAKE) -C ./libft fclean
	@$(MAKE) -C $(MLX_DIR) clean >/dev/null
	@rm -rf $(MLX)
	@rm -rf $(NAME)

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re
