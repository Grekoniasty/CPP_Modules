NAME    = PhoneBook
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAKEFLAGS 		= --no-print-directory -s

SRCS    = PhoneBook.cpp main.cpp Contact.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	echo "PhoneBook compiled successfully!"

clean:
	rm -f $(OBJS)
	echo "PhoneBook object files cleaned!"

fclean: clean
	rm -f $(NAME)
	echo "PhoneBook cleaned completely!"
re: fclean all

.PHONY: all clean fclean re
