CC			= cc
CFLAGS		= -Wall -Wextra -Werror

MANDATORY_DIR	= Mandatory

MLX_FLAGS	=  -lmlx -framework OpenGL -framework AppKit -lm 

MANDATORY_SRC	= $(MANDATORY_DIR)/index.c \
				  $(MANDATORY_DIR)/julia.c \
				  $(MANDATORY_DIR)/init.c \
				  $(MANDATORY_DIR)/draw.c \
				  $(MANDATORY_DIR)/utils.c \
				  $(MANDATORY_DIR)/mandelbrot.c \
				  $(MANDATORY_DIR)/mouse_and_keys.c \
				  $(MANDATORY_DIR)/is_valid_float.c \
				  $(MANDATORY_DIR)/helper.c\
				  ${MANDATORY_DIR}/parser.c

MANDATORY_OBJS	= $(MANDATORY_SRC:.c=.o)



NAME		= fractol

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MANDATORY_OBJS) 
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(MLX_FLAGS)  -o $(NAME)

Mandatory/%.o: Mandatory/%.c Mandatory/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all
