NAME = libftprintf.a
 
SRCS = 	
		
OBJ = $(SRCS:.c=.o)

BONUSOBJ = $(BONUS:.c=.o)

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -f

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean 
		$(RM) $(NAME)

re :	fclean $(NAME) 

.PHONY: all clean fclean re

