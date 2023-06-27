# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:30:34 by tde-souz          #+#    #+#              #
#    Updated: 2022/10/17 19:59:10 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= push_swap

LIBFT_DIR		= ./libft/
LIBFT			= ./libft/libft.a
INCLUDE			:= -I libft -I headers

GREEN			= \e[38;5;118m
GOLD			= \e[38;5;220m
RESET			= \e[0m
BOLD			= \e[1m

UNAME 			:= $(shell uname)
CC				= cc
CFLAGS			= -Wall -Wextra -Werror $(INCLUDE) -L ./libft -lft
RM				= /bin/rm -f

SRCS 			:= ops/push.c ops/rev_rot.c ops/rot.c ops/swap.c		\
				input/input_parse.c input/input_clear.c					\
				input/input_validchars.c								\
				stack/build_stack.c	stack/destroy_stack.c				\
				stack/set_abs_position.c								\
				stack/get_greater.c stack/get_lesser.c					\
				stack/set_cur_position.c stack/set_init_position.c		\
				utils/order_check.c utils/picker.c utils/get_steps.c	\
				utils/get_shortcut.c utils/get_closest_problem.c		\
				utils/get_magnitude.c utils/get_cheapest.c				\
				utils/swapper.c											\
				main.c

OBJS 			:= $(SRCS:.c=.o)

ifeq ($(UNAME), Darwin)
	CC 			= cc
	LFLAGS 		+= -L ./libft -lft
	CFLAGS		= -Wall -Wextra -Werror $(INCLUDE)
else ifeq ($(UNAME), FreeBSD)
	CC 			= clang
else
	CC 			= cc
	LFLAGS		+= -lbsd -L ./libft -lft
endif

.PHONY:		all clean fclean re show

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS) 
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
			@printf "$(BOLD)$(NAME) [$(GREEN)READY$(RESET)]\n"

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR) extra

.c.o:
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean
			@printf "$(BOLD)$(NAME) [$(GOLD)INFO$(RESET)] - removing objects\n"

fclean:		clean
			$(MAKE) -C $(LIBFT_DIR) fclean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)
			@printf "$(BOLD)$(NAME) [$(GOLD)INFO$(RESET)] - removing program\n"

#ARGS		:= 153 68 276 14 230 251 252 418 100 116 79 188 186 453 164 447 366 36 4 190 133 199 389 338 232 488 289 359 27 95 80 394 22 253 413 15 78 374 162 169 304 211 343 316 114 256 357 423 464 225 183 196 123 323 313 460 424 242 250 385 10 395 388 266 390 3 96 202 260 103 191 45 472 47 49 290 469 99 178 264 335 406 449 229 404 237 450 119 426 493 430 363 88 239 462 73 489 46 300 483

ARGS		:= 2 1 3 4 5

run:
			clear
			./push_swap $(ARGS)
			@printf "$(GREEN)COMMANDS:$(RESET) ";./push_swap $(ARGS) | wc -l

frun:		all run

re:			fclean all

show:
	@printf "UNAME			: $(UNAME)\n"
	@printf "NAME			: $(NAME)\n"
	@printf "COMP			: $(CC)\n"
	@printf "CFLAGS			: $(CFLAGS)\n"
	@printf "LFLAGS			: $(LFLAGS)\n"
	@printf "SRCS			: $(SRCS)\n"
	@printf "OBJS			: $(OBJS)\n"
