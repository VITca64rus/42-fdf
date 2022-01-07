NAME = fdf
CC = gcc
CFLAGS = 
SRC  =  	main.c	ft_read_file.c draw.c

OBJ = $(patsubst %.c,%.o,$(SRC))
INCLUDES = push_swap.h
DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a
LIB_GR = minilibx_macos/libmlx.a

all : $(NAME)

lib : 
	make -sC $(DIR_LIB)
	make -sC minilibx_macos

$(NAME) : lib $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIB_GR) -o $(NAME) -framework OpenGL -framework AppKit

%.o : %.c $(INCLUDES)
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make clean -C $(DIR_LIB)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIB)
	
re : fclean all

.PHONY : all clean fclean re