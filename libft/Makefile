# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 17:15:45 by tde-souz          #+#    #+#              #
#    Updated: 2022/10/17 13:19:59 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								   FILE NAME
NAME		= libft.a
BASE_NAME	= libft

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								  OS SETTINGS
CURRENT_OS	:= $(shell uname)

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								  TEXT CODES
GREEN		= \e[38;5;118m
GOLD		= \e[38;5;220m
RESET		= \e[0m
BOLD		= \e[1m

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									ALIASES
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
ifeq ($(CURRENT_OS), Linux)
CFLAGS		+= -fPIE
endif
RM			= /bin/rm -f
#MAKEFLAGS	+= --silent

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
#								   FOLDERS
BASE_DIR	= base/
EXTRA_DIR	= extra/
HEADER		= -I ./

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								 SOURCE FILES
BASE_SRC	:=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c		\
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

EXTRA_SRC	:=	ft_clean.c ft_throw_error.c

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								 OBJECT FILES
OBJS		:= $(addprefix $(BASE_DIR), $(BASE_SRC:.c=.o))
EXTRA_OBJS	:= $(addprefix $(EXTRA_DIR), $(EXTRA_SRC:.c=.o))
# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									 RULES

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rc $(NAME) $(OBJS)
			@ranlib $(NAME)
			@printf "$(BASE_NAME) [$(BOLD)$(GREEN)READY$(RESET)]\n"

extra:		$(OBJS) $(EXTRA_OBJS)
			ar -rc $(NAME) $(OBJS) $(EXTRA_OBJS)
			@ranlib $(NAME)
			@printf "$(BASE_NAME) [$(BOLD)$(GREEN)READY$(RESET)] - extended version\n"

.c.o:
			$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS) $(EXTRA_OBJS)
			@printf "$(BASE_NAME) [$(BOLD)$(GOLD)INFO$(RESET)] - removing object files\n"

fclean:		clean
			@$(RM) $(NAME)
			@printf "$(BASE_NAME) [$(BOLD)$(GOLD)INFO$(RESET)] - removing archive\n"

re:			fclean all

rextra:		fclean extra

.PHONY:		all clean fclean re rextra extra
