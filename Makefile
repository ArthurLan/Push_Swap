# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 11:26:55 by alanter           #+#    #+#              #
#    Updated: 2018/08/14 12:52:17 by alanter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################## PROJECT ########################

CHECKER = checker
PUSH_SWAP = push_swap

######################## PATHS ########################

CHECKER_PATH = ./make_checker
PUSH_SWAP_PATH = ./make_push_swap

########################## OS ###########################

OS := $(shell uname)

######################### COLOR #########################

BLUE = \033[1;34m
RED = \033[8m\033[1;31m
GREEN = \033[32m
NORMAL = \033[0m
LINE_ERASER = \n\033[1A\033[0K\r

########################## STR ##########################

STR_SUCCESS = $(GREEN)SUCCESS$(BLUE).\n$(NORMAL)

######################### FLAGS #########################

ifeq ($(OS),Darwin)
	FLAGS_DEFAULT = -g3 #-pedantic -Wall -Werror -Wextra -g3 -fsanitize=address
	FLAGS_MLX = -framework OpenGL -framework Appkit
else 
	FLAGS_DEFAULT = -Wall -Werror -Wextra
	FLAGS_MLX = -L/usr/X11/lib -lXext -lX11 -lm
endif
FLAGS_LIB = -L$(LIBMLX_PATH) -lmlx -L$(LIBFT_PATH)\
			            -lft $(FLAGS_MLX)

####################### LIBRARIES #######################

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
ifeq ($(OS),Darwin)
	LIBMLX_PATH = minilibx_macos/
else 
	LIBMLX_PATH = minilibx_x11/
endif
LIBMLX = $(LIBMLX_PATH)libmlx.a

######################## COMMANDS #######################

CC = gcc
MAKE = /usr/bin/make
MOVE = /bin/mv
RM = /bin/rm -f
MKDIR = /bin/mkdir

######################## INCLUDES #######################

INC_DIR = ./includes/ ./libft/includes
ifeq ($(OS),Darwin)
	INC_DIR += ./minilibx
else 
	INC_DIR += ./minilibx_x11
endif
INC_PREF = -I
INC_FILES = ./includes/push_swap.h
INC = $(addprefix $(INC_PREF), $(INC_DIR))

######################### RULES #########################

#all: $(CHECKER) $(PUSH_SWAP)

#$(CHECKER): $(LIBFT) $(LIBMLX)
#	@$(MAKE) -C $(CHECKER_PATH)

#$(PUSH_SWAP):
#	@$(MAKE) -C $(PUSH_SWAP_PATH)

all: 
	@$(MAKE) -C $(CHECKER_PATH)
	@$(MAKE) -C $(PUSH_SWAP_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(LIBMLX):
	@printf "$(BLUE)Compiling $(RED)$@$(BLUE): $(NORMAL)"
	@$(MAKE) -C $(LIBMLX_PATH) > .tmp_proj
	@printf "$(GREEN)SUCCESS\n$(NORMAL)"
	@$(RM) .tmp_proj

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(LIBMLX_PATH) > .tmp_proj
	@$(RM) .tmp_proj
	@$(MAKE) clean -C $(CHECKER_PATH)
	@$(MAKE) clean -C $(PUSH_SWAP_PATH)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(MAKE) fclean -C $(CHECKER_PATH)
	@$(MAKE) fclean -C $(PUSH_SWAP_PATH)

re: fclean all

.PHONY: all clean fclean re
