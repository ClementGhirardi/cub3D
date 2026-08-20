# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/03 13:42:50 by clement-ghi       #+#    #+#              #
#    Updated: 2026/08/14 12:21:29 by clement-ghi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror


#	DIRECTORIES   #
SRC_DIR		= src/
INC_DIR		= includes/
OBJ_DIR		= objects/


#	FILES	#
SRC_FILES = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
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
			ft_putnbr_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_utils_0.c \
			ft_utils_1.c \
			ft_utils_2.c \
			ft_handle_utils_0.c \
			ft_handle_utils_1.c \
			ft_handle_c.c \
			ft_handle_d.c \
			ft_handle_i.c \
			ft_handle_p.c \
			ft_handle_perc.c \
			ft_handle_s.c \
			ft_handle_u.c \
			ft_handle_xlow.c \
			ft_handle_xup.c \
			ft_printf.c \
			get_next_line_utils.c \
			get_next_line.c
OBJ_FILES = $(SRC_FILES:.c=.o)


#	PATHS	#
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_FILES))


#	COLOR CODES AND VARS   #
TOTAL	= $(words $(OBJ))
COUNT	= 0

RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[0;34m
ORANGE	= \033[1;38;5;208m
RESET	= \033[0m


#	RULES   #
all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)
	@printf "$(GREEN)✓ $(NAME) created !$(RESET)\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@printf "$(BLUE)[%02d/%d]$(RESET) Compiling $(YELLOW)%s$(RESET)\n" \
		$(COUNT) $(TOTAL) $<
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@printf "$(ORANGE)~ Cleaning objects$(RESET)\r"
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		printf "$(ORANGE)✓ Libft ➜  Objects cleaned !$(RESET)\n"; \
	else \
		printf "$(ORANGE)~ Libft ➜  No objects to remove.\n$(RESET)"; \
	fi;

fclean: clean
	@printf "$(RED)~ Cleaning $(NAME)$(RESET)\r"
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		printf "$(RED)✓ Libft ➜  Cleaned !$(RESET)\n"; \
	else \
		printf "$(RED)~ Libft ➜  No executable to remove.$(RESET)\n"; \
	fi;

re: fclean all
