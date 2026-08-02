NAME    = BraiiiiiiinnnzzzZ
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAKEFLAGS 		= --no-print-directory -s

SRCS    = zombies.cpp main.cpp zombies.hpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	echo "BraiiiiiiinnnzzzZ compiled successfully!"

clean:
	rm -f $(OBJS)
	echo "BraiiiiiiinnnzzzZ object files cleaned!"

fclean: clean
	rm -f $(NAME)
	echo "BraiiiiiiinnnzzzZ cleaned completely!"
re: fclean all

.PHONY: all clean fclean re
