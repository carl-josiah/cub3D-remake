NAME := cub3D

CC := cc -g3
CFLAGS := # -Wall -Wextra -Werror

RM := rm -f
RMDIR := rm -rf

SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
MLX_DIR := minilibx-linux

PARSE_DIR := $(SRC_DIR)/parse
ERROR_DIR := $(SRC_DIR)/error
INIT_DIR := $(SRC_DIR)/init
VALIDATE_DIR := $(SRC_DIR)/validate
FREE_DIR := $(SRC_DIR)/free
PRINT_DIR := $(SRC_DIR)/print

LIB := $(LIB_DIR)/libft.a
MLX := $(MLX_DIR)/libmlx.a
MLX_FLAGS := -lXext -lX11 -lm

PARSE_SRC := $(addprefix $(PARSE_DIR)/,	config/parse_config.c parse_map.c parse_scene.c read_scene.c \
										parse_utils.c config/parse_color.c config/parse_texture.c)
ERROR_SRC := $(addprefix $(ERROR_DIR)/,	error_arguments.c error_system.c error_parse.c)
INIT_SRC := $(addprefix $(INIT_DIR)/,	init_game.c)
VALIDATE_SRC := $(addprefix $(VALIDATE_DIR)/,	validate_arguments.c)
FREE_SRC := $(addprefix $(FREE_DIR)/,	free_game.c)
PRINT_SRC := $(addprefix $(PRINT_DIR)/,	print_lines.c print_bits.c print_state.c print_paths.c)

SRC := $(SRC_DIR)/cub3D.c	$(PARSE_SRC) $(ERROR_SRC) $(INIT_SRC) \
	   						$(VALIDATE_SRC) $(FREE_SRC) $(PRINT_SRC)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDE := -Iinclude -I$(LIB_DIR) -I$(MLX_DIR)

all: lib mlx $(NAME)

mlx:
	$(MAKE) -C $(MLX_DIR) all

lib:
	$(MAKE) -C $(LIB_DIR) all

$(NAME): $(OBJ) $(LIB) $(MLX)
	$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

mlx-clean:
	$(MAKE) -C $(MLX_DIR) clean

mlx-re:
	$(MAKE) -C $(MLX_DIR) re 

lib-clean:
	$(MAKE) -C $(LIB_DIR) clean

lib-fclean:
	$(MAKE) -C $(LIB_DIR) fclean

lib-re:
	$(MAKE) -C $(LIB_DIR) re

clean: mlx-clean lib-clean
	$(RMDIR) $(OBJ_DIR)

fclean: clean lib-fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.PHONY: mlx mlx-clean mlx-re

.PHONY: lib lib-clean lib-fclean lib-re
