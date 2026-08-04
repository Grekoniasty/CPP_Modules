NAME    = megaphone
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAKEFLAGS 		= --no-print-directory -s

SRCS    = megaphone.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	echo "Megaphone compiled successfully!"

clean:
	rm -f $(OBJS)
	echo "Megaphone object files cleaned!"

fclean: clean
	rm -f $(NAME)
	echo "Megaphone cleaned completely!"

re: fclean all

.PHONY: all clean fclean re
