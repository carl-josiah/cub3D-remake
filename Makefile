NAME := cub3D

CC := cc
CFLAGS := -Wall -Wextra -Werror

RM = rm -f
RMDIR = rm -rf

SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
MLX_DIR := minilibx-linux

LIB := $(LIB_DIR)/libft.a
MLX := $(MLX_DIR)/libmlx.a
MLX_FLAGS := -lXext -lX11 -lm

SRC := $(SRC_DIR)/cub3D.c
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
	@mkdir -p $(OBJ_DIR)
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
	$(RM) $(OBJ_DIR)

fclean: clean lib-fclean
	$(RMDIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.PHONY: mlx mlx-clean mlx-re

.PHONY: lib lib-clean lib-fclean lib-re
