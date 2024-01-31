NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror

OUT = -o $(NAME)

SOURCES = src/pipex.c \
	  src/pipex_utils.c \
	  src/pipex_utils1.c \
	  src/pipex_utils2.c \
	  src/pipex_utils3.c \
	  src/pipex_comand_checker.c \
	  src/freematrix_two.c \
	  src/ft_split.c \
	  src/ft_split_cmds.c

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
