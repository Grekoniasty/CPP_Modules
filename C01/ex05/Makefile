NAME    = Harl_2_0
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAKEFLAGS		= --no-print-directory -s

SRCS    = main.cpp Harl.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	echo "Harl 2.0 compiled successfully!"

clean:
	rm -f $(OBJS)
	echo "Harl 2.0 object files cleaned!"

fclean: clean
	rm -f $(NAME)
	echo "Harl 2.0 cleaned completely!"

re: fclean all

.PHONY: all clean fclean re
