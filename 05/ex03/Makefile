NAME=forms
CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRCS=main.cpp \
	 Bureaucrat.cpp \
	 AForm.cpp \
	 ShrubberryCreationForm.cpp \
	 RobotomyRequestForm.cpp \
	 PresidentialPardonForm.cpp \
	 Intern.cpp
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