# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 11:11:09 by rliu              #+#    #+#              #
#    Updated: 2022/09/09 11:30:09 by qxia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_strnstr.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c\
		ft_strcmp.c \

GNL_SRCS		=	get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \
					get_next_line/get_next_line_nodes.c \

CC				=	gcc
RM				=	rm -rf
AR				=	ar rcs

LIBFT_A			=	libft.a

OBJS			=	$(SRCS:.c=.o)
GNL_OBJS		=	$(GNL_SRCS:.c=.o)

INCS			=	libft.h \
					get_next_line/get_next_line.h \

%.o				:	%.c $(INCS)
					$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A)		:	$(OBJS) $(GNL_OBJS)
					$(AR) $(LIBFT_A) $(OBJS) $(GNL_OBJS)

all				:	$(LIBFT_A)

clean			:
					$(RM) $(OBJS) $(GNL_OBJS)

fclean			:	clean
					$(RM) $(LIBFT_A)

re				:	fclean all

.PHONY			:	all clean fclean re