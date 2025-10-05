NAME = philo

SRC = src/
ACTIONS = $(SRC)actions/
INIT = $(SRC)init/
UTILS = $(SRC)utils/
SUPERVISOR = $(SRC)supervisor/
EVENTS = $(SRC)event/
QUEUE = $(SRC)queue/

SRC_FILES =  $(wildcard $(SRC)*.c)
SRC_FILES += $(wildcard $(ACTIONS)*.c)
SRC_FILES += $(wildcard $(INIT)*.c)
SRC_FILES += $(wildcard $(UTILS)*.c)
SRC_FILES += $(wildcard $(SUPERVISOR)*.c)
SRC_FILES += $(wildcard $(EVENTS)*.c)
SRC_FILES += $(wildcard $(QUEUE)*.c)

SRC_OBJS = $(SRC_FILES:.c=.o)

##Libriaries
INCLUDES = -Iincludes/

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
DFLAGS = $(INCLUDES) -g -fsanitize=address

all : $(NAME)

bonus : $(NAME)

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) -o $(NAME)
debug:
	$(MAKE) CFLAGS="$(DFLAGS)" $(NAME)

debug-re: fclean
	$(MAKE) CFLAGS="$(DFLAGS)" $(NAME)

clean :
	rm -f $(SRC_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus debug