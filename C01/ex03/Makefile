NAME    = violence
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAKEFLAGS		= --no-print-directory -s

SRCS    = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	echo "violence compiled successfully!"

clean:
	rm -f $(OBJS)
	echo "violence object files cleaned!"

fclean: clean
	rm -f $(NAME)
	echo "violence cleaned completely!"

re: fclean all

.PHONY: all clean fclean re
