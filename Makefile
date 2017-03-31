


NAME 	= rtv1
OBJS 	= $(SRC:.c=.o)
CC 		= gcc
FLAGS 	= -Wall -Werror -Wextra
LIB 	= libft/libft.a
LIBMLX 	= minilibx_macos/libmlx.a
LMX 	= -framework OpenGL -framework AppKit 
SRC 	= 	src/ray_trace2.c \
			src/mlbx.c \
			src/sphere.c \
			src/tokenizer.c \
			src/token_elem.c \
			src/token_material.c \
			src/token_sphere.c \
			src/token_light.c \
			src/vectors.c 

all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(LIBMLX)
				@$(CC) $(FLAGS) $(LMX) $(SRC) $(LIB) $(LIBMLX) -o $(NAME)

$(LIBMLX):
				@make -s -C minilibx_macos
$(LIB):
				@make -s -C libft

%.o : %.c
				@$(CC) -o $@ -c $< $(FLAGS)

clean:
				@rm -f $(OBJS)

fclean: clean
				@make fclean -s -C libft/ 
				@make clean -s -C minilibx_macos/ 
				@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
