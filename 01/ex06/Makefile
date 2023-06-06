NAME=harlFilter
CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98 -Wimplicit-fallthrough=0
SRCS=main.cpp \
	 Harl.cpp
OBJS=$(SRCS:%.cpp=%.o)

all :   $(NAME)

$(NAME)     :   $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I .

clean   :
	rm -f $(OBJS)

fclean  :   clean
	rm -f $(NAME)

re  :   fclean all

.PHONY  :   all clean fclean re