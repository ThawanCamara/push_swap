# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:30:34 by tde-souz          #+#    #+#              #
#    Updated: 2022/07/23 04:40:50 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								   FILE NAME
NAME		= libft

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								  TEXT CODES
GREEN		= \e[38;5;118m
GOLD		= \e[38;5;220m
RESET		= \e[0m
BOLD		= \e[1m

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									ALIASES
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= /bin/rm -f
MAKEFLAGS	+= --silent

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								 SOURCE FILES
SRCS := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c		\
		ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c				\
		ft_memmove.c ft_memset.c												\
		ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c			\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c			\
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c						\
		ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c							\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c			\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c					\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c				\
		ft_lstmap.c																\
		get_next_line.c get_next_line_utils.c									\
		ft_printf.c ft_printf_utils_char.c ft_printf_utils_int.c				\
		ft_printf_utils_hex.c											

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								 OBJECT FILES
OBJS := ${SRCS:.c=.o}

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									 RULES
.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME).a $(OBJS)
			@ranlib $(NAME).a
			@printf "$(BOLD)$(NAME) [$(GREEN)READY$(RESET)]\n"
clean:
			@$(RM) $(OBJS)
			@printf "$(BOLD)$(NAME) [$(GOLD)INFO$(RESET)] - removing objects\n"

fclean:		clean
			@$(RM) $(NAME).a
			@printf "$(BOLD)$(NAME) [$(GOLD)INFO$(RESET)] - removing library\n"

re:			fclean all


