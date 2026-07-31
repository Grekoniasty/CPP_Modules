NAME    = zombieHorde
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAKEFLAGS 		= --no-print-directory -s

SRCS    = zombieHorde.cpp main.cpp zombies.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	echo "zombieHorde compiled successfully!"

clean:
	rm -f $(OBJS)
	echo "zombieHorde object files cleaned!"

fclean: clean
	rm -f $(NAME)
	echo "zombieHorde cleaned completely!"
re: fclean all

.PHONY: all clean fclean re