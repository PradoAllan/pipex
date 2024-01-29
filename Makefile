NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror

OUT = -o $(NAME)

SOURCES = pipex.c \
	  pipex_utils.c \
	  pipex_utils1.c \
	  pipex_utils2.c \
	  pipex_utils3.c \
	  pipex_comand_checker.c \
	  ft_split.c \
	  ft_split_cmds.c

OBJECTS = ${SOURCES:.c=.o}

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(OUT)

all : $(NAME)

clean : 
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
