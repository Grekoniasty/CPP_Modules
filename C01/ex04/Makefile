NAME    = sed
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAKEFLAGS		= --no-print-directory -s

SRCS    = main.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	echo "sed compiled successfully!"

clean:
	rm -f $(OBJS)
	echo "sed object files cleaned!"

fclean: clean
	rm -f $(NAME)
	echo "sed cleaned completely!"

re: fclean all

.PHONY: all clean fclean re
