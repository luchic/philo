NAME = fractol

SRC = src/
SRC_FILES =  $(wildcard $(SRC)*.c)

SRC_OBJS = $(SRC_FILES:.c=.o)

##Libriaries

#Libft
DLIBFT = libft
LIBFT = $(DLIBFT)/libft.a
FT = ft


CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

# bonus: $(NAME)

$(NAME): $(LIBFT) $(SRC_OBJS)
	cc $(CFLAGS) $^ -o $@ -L$(DLIBFT) -l$(FT) -L$(BUILD_DIR) -lmlx42 $(EXT_LIBS)

$(LIBFT) :
	make -C $(DLIBFT) all

re : fclean all

fclean : clean
	rm -f $(NAME)
	make -C $(DLIBFT) fclean
	rm -rf $(MLX42)

clean : 
	rm -f $(SRC_OBJS)
	make -C $(DLIBFT) clean

.PHONY: all clean fclean re bonus #debug debug_bonus