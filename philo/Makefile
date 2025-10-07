NAME = philo

SRC = src/
ACTIONS = $(SRC)actions/
INIT = $(SRC)init/
UTILS = $(SRC)utils/
SUPERVISOR = $(SRC)supervisor/
EVENTS = $(SRC)event/
QUEUE = $(SRC)queue/

# Main
SRC_FILES =  $(SRC)main.c

# Actions
SRC_FILES += $(ACTIONS)action.c
SRC_FILES += $(ACTIONS)eating.c
SRC_FILES += $(ACTIONS)thinking.c
SRC_FILES += $(ACTIONS)sleeping.c

# Events
SRC_FILES += $(EVENTS)get_event.c
SRC_FILES += $(EVENTS)send_event.c
SRC_FILES += $(EVENTS)end_iter.c

# Inits
SRC_FILES += $(INIT)init_forks.c
SRC_FILES += $(INIT)init.c
SRC_FILES += $(INIT)parser.c
SRC_FILES += $(INIT)setup_forks.c

# Queue
SRC_FILES += $(QUEUE)qinit.c
SRC_FILES += $(QUEUE)operations.c
SRC_FILES += $(QUEUE)checker.c

# Supervisor
SRC_FILES += $(SUPERVISOR)visor.c
SRC_FILES += $(SUPERVISOR)life_monitoring.c

# Utils
SRC_FILES += $(UTILS)char_checker.c
SRC_FILES += $(UTILS)ft_atoi.c
SRC_FILES += $(UTILS)life_checker.c
SRC_FILES += $(UTILS)sleep.c
SRC_FILES += $(UTILS)validator.c


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