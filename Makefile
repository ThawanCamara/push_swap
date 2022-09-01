# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:30:34 by tde-souz          #+#    #+#              #
#    Updated: 2022/09/01 01:09:54 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								   FILE NAME
NAME		= push_swap

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								  DIRECTORIES
LIBFT		= libft
LIBFT_DIR	= ./libft/

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								  TEXT CODES
GREEN		= \e[38;5;118m
GOLD		= \e[38;5;220m
RESET		= \e[0m
BOLD		= \e[1m

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									ALIASES
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= /bin/rm -f
#MAKEFLAGS	+= --silent

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								 SOURCE FILES
SRCS := push_swap.c			\
		stack_base.c		\
		error_manager.c		\
		swap.c				\
		push.c				\
		rot.c				\
		rev.c				\
		list_ops.c			\
		main.c

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								 OBJECT FILES
OBJS := ${SRCS:.c=.o}

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									 RULES
.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT).a -o $(NAME)
			@printf "$(BOLD)$(NAME) [$(GREEN)READY$(RESET)]\n"

clean:
			@$(MAKE) -C $(LIBFT_DIR) clean
			@$(RM) $(OBJS)
			@printf "$(BOLD)$(NAME) [$(GOLD)INFO$(RESET)] - removing objects\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT_DIR)$(LIBFT).a
			@printf "$(BOLD)$(NAME) [$(GOLD)INFO$(RESET)] - removing program\n"

run:		
				./push_swap 1 2 3 4 5 6

frun:		all run

re:			fclean all

