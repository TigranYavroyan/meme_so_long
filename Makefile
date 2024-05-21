NAME = so_long
SRCSPATH = ./srcs/
PRINTF_PATH = ./printf/
LIBFTPATH = ./libft/
INCPATH = ./includes/ ./printf/includes/ ./printf/libft/
SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c,$(SRCSPATH)%.o,$(SRCS))
PRINTF = $(PRINTF_PATH)/srcs/*.o
LIBFT = $(LIBFTPATH)*.o

CC = cc
CFLAGS = -Wall -Wextra  $(foreach H,$(INCPATH),-I$(H))
#-Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGl -framework Appkit -lm

all : $(NAME)
$(NAME) : $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) -fsanitize=address -g $(MLXFLAGS) $(LIBFT) $(PRINTF) $(OBJS) -o $(NAME)
#-fsanitize=address
$(LIBFT) :
	make -C $(LIBFTPATH) all

$(PRINTF) :
	make -C $(PRINTF_PATH) all

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C $(PRINTF_PATH) clean
	make -C $(LIBFTPATH) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(PRINTF_PATH) fclean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
