NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC  =  	main.c	ft_read_file.c draw.c ft_help.c

OBJ = $(patsubst %.c,%.o,$(SRC))
INCLUDES = push_swap.h
DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a

all : $(NAME)

lib : 
	@make -C $(DIR_LIB)

$(NAME) : lib $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

%.o : %.c $(INCLUDES)
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -C $(DIR_LIB) clean

fclean : clean
	rm -f $(NAME)
	make -C $(DIR_LIB) fclean
	
re : fclean all

.PHONY : all clean fclean re