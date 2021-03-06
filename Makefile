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
			src/tokenizer/tokenizer.c \
			src/tokenizer/token_elem.c \
			src/tokenizer/token_elem_compose.c \
			src/tokenizer/token_detect_sphere.c \
			src/tokenizer/token_detect_cyl.c \
			src/tokenizer/token_detect_plan.c \
			src/tokenizer/token_detect_cone.c \
			src/tokenizer/token_material.c \
			src/tokenizer/token_sphere.c \
			src/tokenizer/token_light.c \
			src/tokenizer/token_plan.c \
			src/tokenizer/token_cyl.c \
			src/tokenizer/token_cone.c \
			src/tokenizer/token_detect.c \
			src/tokenizer/token_utils.c \
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
