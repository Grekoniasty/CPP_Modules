NAME    = TheJobOfYourDreams
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAKEFLAGS 		= --no-print-directory -s

SRCS    = tests.cpp Account.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	echo "TheJobOfYourDreams compiled successfully!"

clean:
	rm -f $(OBJS)
	echo "TheJobOfYourDreams object files cleaned!"
fclean: clean
	rm -f $(NAME)
	echo "TheJobOfYourDreams cleaned completely!"
re: fclean all

.PHONY: all clean fclean re
