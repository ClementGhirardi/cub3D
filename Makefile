# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/03 13:42:50 by clement-ghi       #+#    #+#              #
#    Updated: 2026/08/27 12:46:50 by clement-ghi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

NAME			= cub3D
NAME_BONUS		= cub3D_bonus
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
LIBFT_FLAGS		= -lft
LIBMLX_FLAGS	= -lmlx -lXext -lX11 -lm -lz


#	DIRECTORIES   #
SRC_DIR			= src/
INC_DIR			= includes/
OBJ_DIR			= objects/

SRC_BONUS_DIR	= src_bonus/
INC_BONUS_DIR	= includes_bonus/
OBJ_BONUS_DIR	= objects_bonus/

LIBFT_DIR		= libft/
LIBMLX_DIR		= minilibx-linux/


#	FILES	#
SRC_FILES = main.c \
			initialization/init_img.c \
			initialization/init_config.c \
			initialization/init_map.c \
			initialization/init_keys.c \
			initialization/init_player.c \
			initialization/init_mlx.c \
			initialization/init_data.c \
			cleanup/destroy_mlx.c \
			cleanup/free_config.c \
			cleanup/free_map.c \
			cleanup/free_data.c \
			parsing/utils.c \
			parsing/get_line_type.c \
			parsing/read_file_lines.c \
			parsing/parse_texture.c \
			parsing/parse_color.c \
			parsing/parse_config.c \
			parsing/extract_map.c \
			parsing/validate_map_chars.c \
			parsing/validate_map_closed.c \
			parsing/validate_map.c \
			parsing/parse_file.c \
			mlx/init_mlx_window.c \
			mlx/init_frame.c \
			mlx/load_textures.c \
			mlx/put_pixel.c \
			mlx/get_pixel.c \
			player/can_move_to.c \
			player/move_player.c \
			player/strafe_player.c \
			player/rotate_player.c \
			hooks/close_game.c \
			hooks/key_press.c \
			hooks/key_release.c \
			hooks/init_hooks.c \
			ray_casting/init_ray.c \
			ray_casting/init_delta.c \
			ray_casting/init_step_side.c \
			ray_casting/perform_dda.c \
			ray_casting/cast_ray.c \
			ray_casting/render_frame.c \
			error/error.c

HEADER_FILES =	cub3d.h
				
OBJ_FILES =	$(SRC_FILES:.c=.o)

SRC_BONUS_FILES = main_bonus.c \
			initialization/init_img_bonus.c \
			initialization/init_config_bonus.c \
			initialization/init_map_bonus.c \
			initialization/init_keys_bonus.c \
			initialization/init_player_bonus.c \
			initialization/init_mlx_bonus.c \
			initialization/init_sprites_bonus.c \
			initialization/init_doors_bonus.c \
			initialization/init_projectiles_bonus.c \
			initialization/init_data_bonus.c \
			cleanup/destroy_mlx_bonus.c \
			cleanup/free_sprites_bonus.c \
			cleanup/free_doors_bonus.c \
			cleanup/free_config_bonus.c \
			cleanup/free_map_bonus.c \
			cleanup/free_data_bonus.c \
			parsing/utils_bonus.c \
			parsing/get_line_type_bonus.c \
			parsing/read_file_lines_bonus.c \
			parsing/parse_texture_bonus.c \
			parsing/parse_color_bonus.c \
			parsing/parse_config_bonus.c \
			parsing/extract_map_bonus.c \
			parsing/validate_map_chars_bonus.c \
			parsing/extract_sprites_bonus.c \
			parsing/validate_map_closed_bonus.c \
			parsing/validate_map_doors_bonus.c \
			parsing/extract_doors_bonus.c \
			parsing/validate_map_bonus.c \
			parsing/parse_file_bonus.c \
			mlx/init_mlx_window_bonus.c \
			mlx/init_frame_bonus.c \
			mlx/load_textures_bonus.c \
			mlx/put_pixel_bonus.c \
			mlx/get_pixel_bonus.c \
			player/can_move_to_bonus.c \
			player/move_player_bonus.c \
			player/strafe_player_bonus.c \
			player/rotate_player_bonus.c \
			hooks/close_game_bonus.c \
			hooks/key_press_bonus.c \
			hooks/key_release_bonus.c \
			hooks/handle_mouse_bonus.c \
			hooks/init_hooks_bonus.c \
			ray_casting/init_ray_bonus.c \
			ray_casting/init_delta_bonus.c \
			ray_casting/init_step_side_bonus.c \
			ray_casting/perform_dda_bonus.c \
			ray_casting/cast_ray_bonus.c \
			ray_casting/render_frame_bonus.c \
			minimap/minimap_utils_bonus.c \
			minimap/draw_minimap_tiles_bonus.c \
			minimap/draw_minimap_rays_bonus.c \
			minimap/draw_minimap_square_bonus.c \
			minimap/draw_minimap_circle_bonus.c \
			minimap/draw_minimap_bonus.c \
			doors/open_door_bonus.c \
			doors/update_doors_bonus.c \
			doors/get_door_at_bonus.c \
			doors/ray_hit_door_bonus.c \
			sprites/sort_sprites_bonus.c \
			sprites/draw_sprite_bonus.c \
			sprites/load_sprites_bonus.c \
			sprites/update_sprites_bonus.c \
			sprites/reset_sprite_z_buffer_bonus.c \
			sprites/render_sprites_bonus.c \
			projectiles/shoot_projectile_bonus.c \
			projectiles/update_projectiles_bonus.c \
			projectiles/render_projectiles_bonus.c \
			error/error_bonus.c
			
HEADER_BONUS_FILES = cub3d_bonus.h
				
OBJ_BONUS_FILES =$(SRC_BONUS_FILES:.c=.o)


#	PATHS	#
SRC		= $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJ		= $(addprefix $(OBJ_DIR),$(OBJ_FILES))
HEADERS = $(addprefix $(INC_DIR),$(HEADER_FILES))

SRC_BONUS		= $(addprefix $(SRC_BONUS_DIR),$(SRC_BONUS_FILES))
OBJ_BONUS		= $(addprefix $(OBJ_BONUS_DIR),$(OBJ_BONUS_FILES))
HEADERS_BONUS	= $(addprefix $(INC_BONUS_DIR),$(HEADER_BONUS_FILES))

LIBFT	= $(LIBFT_DIR)libft.a
LIBMLX	= $(LIBMLX_DIR)libmlx.a


#	COLOR CODES AND VARS   #
TOTAL		= $(words $(OBJ))
TOTAL_BONUS	= $(words $(OBJ_BONUS))
COUNT		= 0

RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[0;34m
B_BLUE	= \033[1;34m
ORANGE	= \033[1;38;5;208m
RESET	= \033[0m


#	RULES   #
all: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -L$(LIBMLX_DIR) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -o $(NAME)
	@printf "$(GREEN)✓ $(NAME) created !$(RESET)\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@printf "$(BLUE)[%02d/%d]$(RESET) Compiling $(YELLOW)%s$(RESET)\n" \
		$(COUNT) $(TOTAL) $<
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBMLX) $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -L$(LIBFT_DIR) -L$(LIBMLX_DIR) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -o $(NAME)_bonus
	@printf "$(GREEN)✓ $(NAME)_bonus created !$(RESET)\n\n"

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c $(HEADERS_BONUS)
	@mkdir -p $(dir $@)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@printf "$(BLUE)[%02d/%d]$(RESET) Compiling $(YELLOW)%s$(RESET)\n" \
		$(COUNT) $(TOTAL_BONUS) $<
	@$(CC) $(CFLAGS) -I $(INC_BONUS_DIR) -c $< -o $@

$(LIBFT):
	@printf "$(B_BLUE)~ Compiling Libft$(RESET)\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@printf "$(B_BLUE)~ Compiling $(NAME)$(RESET)\n"

$(LIBMLX):
	@printf "$(B_BLUE)~ Compiling MLX$(RESET)\n"
	@tar xvzf minilibx-linux.tgz
	@$(MAKE) --no-print-directory -C $(LIBMLX_DIR)
	@printf "$(GREEN)✓ MLX created !$(RESET)\n\n"

clean:
	@printf "$(ORANGE)~ Cleaning objects$(RESET)\r"
	@if [ -d "$(LIBMLX_DIR)" ]; then \
		rm -rf $(LIBMLX_DIR); \
		printf "$(RED)✓ MLX ➜  Cleaned !$(RESET)\n"; \
	else \
		printf "$(RED)~ MLX ➜  Already removed.\n$(RESET)"; \
	fi;
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		printf "$(ORANGE)✓ $(NAME) ➜  Objects cleaned !$(RESET)\n"; \
	else \
		printf "$(ORANGE)~ $(NAME) ➜  No objects to remove.\n$(RESET)"; \
	fi;
	@if [ -d "$(OBJ_BONUS_DIR)" ]; then \
		rm -rf $(OBJ_BONUS_DIR); \
		printf "$(ORANGE)✓ bonus ➜  Objects cleaned !$(RESET)\n"; \
	fi;

fclean: clean
	@printf "$(RED)~ Cleaning $(NAME)$(RESET)\r"
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		printf "$(RED)✓ $(NAME) ➜  Cleaned !$(RESET)\n"; \
	else \
		printf "$(RED)~ $(NAME) ➜  No executable to remove.$(RESET)\n"; \
	fi;
	@if [ -f "$(NAME_BONUS)" ]; then \
		rm -f $(NAME_BONUS); \
		printf "$(RED)✓ bonus ➜  Cleaned !$(RESET)\n"; \
	fi;

re: fclean all
