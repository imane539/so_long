CFLAGS = -Wall -Werror -Wextra  #-fsanitize=address -g3 #-ggdb3

SRC =so_long.c parsing.c \
map_operations.c \
bfs.c \
utils.c \
screen.c \
queue_operations.c \
components.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c

LIBFT = libft/libft.a

# SRCB = 

OBJECTS =$(SRC:.c=.o)

# OBJECTSB =$(SRCB:.c=.o)

NAME = so_long
# NAME_BONUS = checker

all:$(NAME)

$(NAME):$(OBJECTS) $(LIBFT)
	cc	$(CFLAGS) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	make -C libft

# bonus:$(NAME_BONUS)

# $(NAME_BONUS):$(OBJECTSB) $(LIBFT)
# 	cc	$(CFLAGS) $^ -o $(NAME_BONUS)


clean :
	make clean -C libft
	rm -f $(OBJECTS) 
#rm -f $(OBJECTSB) 

	
fclean : clean 
	make fclean -C libft
	rm -f $(NAME)
#rm -f $(NAME_BONUS)

re : fclean all

# .PHONY:re all fclean clean 

.SECONDARY : $(OBJECTS) $(OBJECTSB)