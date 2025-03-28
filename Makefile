COMPILER = cc

COMPILER_FLAGS = -Wall -Wextra -Werror 

LIBS = -L/usr/include/minilibx-linux -lmlx -lXext -lX11

SOURCE_FILES = mandatory/so_long.c mandatory/game.c mandatory/hooks.c mandatory/moves.c\
mandatory/clean.c mandatory/valid_map.c mandatory/swap_positions.c

BONUS_FILES = bonus_src/so_long_bonus.c bonus_src/game_bonus.c bonus_src/clean_bonus.c\
bonus_src/hooks_bonus.c bonus_src/valid_map_bonus.c bonus_src/moves_bonus.c\
bonus_src/swap_positions_bonus.c bonus_src/display_images_bonus.c

UTILS = utils/check_map.c utils/clear.c utils/check_valid_map.c\
utils/find_position.c utils/is_rectangle.c utils/valid_extension.c\
utils/map_size.c utils/parse_map.c utils/map_utils.c utils/file_to_image.c\

MANDATORY_OBJECTS = $(SOURCE_FILES:.c=.o)

BONUS_OBJECTS = $(BONUS_FILES:.c=.o)

UTILS_OBJECTS = $(UTILS:.c=.o)

NAME = so_long

NAME_1 = so_long_bonus

LIB_DIR = libft

LIBFT = libft/libft.a

RM = rm -f

all: $(NAME)

%.o: %.c 
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

$(NAME): $(MANDATORY_OBJECTS) $(UTILS_OBJECTS) $(LIBFT)
	$(COMPILER) $(COMPILER_FLAGS) $(MANDATORY_OBJECTS) $(UTILS_OBJECTS) $(LIBFT) $(LIBS) -o $(NAME)

$(NAME_1): $(BONUS_OBJECTS) $(UTILS_OBJECTS) $(LIBFT)
	$(COMPILER) $(COMPILER_FLAGS) $(BONUS_OBJECTS) $(UTILS_OBJECTS) $(LIBFT) $(LIBS) -o $(NAME_1)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

bonus: $(NAME_1)

clean:
	$(RM) $(MANDATORY_OBJECTS) $(UTILS_OBJECTS) $(BONUS_OBJECTS)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(NAME_1)

re: fclean all

.PHONY: all clean fclean re bonus