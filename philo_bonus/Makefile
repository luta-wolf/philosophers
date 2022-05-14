NAME	=	philo_bonus

SRCS	=	src/philo_bonus.c		src/philo_bonus_utils.c	\
			src/philo_bonus_init.c	#src/philo_bonus_life.c

OBJ		=	$(SRCS:%.c=%.o)

INCLUDE	=	include/

HEADER	=	philo_bonus.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
GRN		=	\033[32m
GRN_B	=	\033[1;32m
WHT		=	\x1B[37m
PUPURE	=	\033[1;35m
MAG		=	\x1B[35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m

# define RED    "\x1b[31m"
# define BLU    "\x1B[34m"
# define GRN    "\x1B[32m"
# define YEL    "\x1B[33m"
# define MAG    "\x1B[35m"
# define CYN    "\x1B[36m"
# define WHT    "\x1B[37m"

#---------------------------------------------------------------------------------
.PHONY:		all	clean	fclean	re

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			@echo "$(GRN)\n\t $(NAME) is complited  \n$(END)"

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@echo "$(BLUE)\n\tCleaning $(NAME) succeed \n$(END)"

fclean:		clean
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\tDeleting $(NAME) succeed\n$(END)"

re:			fclean all
			@echo "$(BLUE)\tRemake done\n$(END)"


