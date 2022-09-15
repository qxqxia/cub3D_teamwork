# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 14:09:27 by qxia              #+#    #+#              #
#    Updated: 2022/09/15 14:31:37 by qxia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang
RM		=	rm -rf
AR		=	ar rcs
NAME		=	cub3D
BONUS		=	cub3D_bonus
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-Lmlx -lbsd -lXext -lX11 -lm
SRCS_DIR	=	srcs
INCS_DIR	=	incs
SRCS		=	main.c \
				parser/parse_map.c \
				parser/ft_get_info.c parser/ft_get_info_utile.c \
				parser/check_map_util.c \
				parser/ft_get_map.c \
				parser/check_map.c \
				parser/ft_player.c \
				exec/ft_print_smallmap.c \
				exec/ft_print_graphic.c \
				exec/ft_init_images.c \
				exec/ft_init_graphic.c \
				events/close_game.c \
				events/ft_move.c \
				events/ft_key_control.c \
				ft_return.c \
				ft_free_cub3d.c \

INCS		=	cub3d.h 

# **************************************************************************** #
#       LIBRARIES                                                              #
# **************************************************************************** #
LIBFT_A		=	libft.a
LIBFT_DIR	=	libft
LIBMLX_A	=	libmlx.a
LIBMLX_DIR	=	mlx


# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

%.o		:	%.c
				$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@ 

$(NAME)		:	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
				$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(LIBMLX_A) $(MLX_FLAGS)

$(BONUS)	:	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
				$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(LIBMLX_A) $(MLX_FLAGS)

$(LIBFT_A)	:
			make -C $(LIBFT_DIR) $(LIBFT_FLAGS)
			mv $(LIBFT_DIR)/$(LIBFT_A) .

$(LIBMLX_A)	:
			make -C $(LIBMLX_DIR)
			mv $(LIBMLX_DIR)/$(LIBMLX_A) .

all		:	$(NAME)

bonus		:	$(BONUS)

clean		:
			$(RM) $(OBJS) $(LIBFT_A)
			make clean -C $(LIBFT_DIR)
			make clean -C $(LIBMLX_DIR)

fclean		:	clean
				$(RM) $(NAME)
				$(RM) $(BONUS)
				$(RM) $(LIBFT_A)
				$(RM) $(LIBMLX_A)
				make fclean -C $(LIBFT_DIR)

re		:	fclean all

.PHONY		:	all bonus clean fclean re
