NAME=phonebook
CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRCS=./Contact.cpp \
	 ./PhoneBook.cpp \
	 ./main.cpp
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