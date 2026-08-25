NAME		= ClapTrap

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

INCDIR		= include
SRCDIR		= src

SRCS		= $(wildcard $(SRCDIR)/*.cpp)
HEADERS		= $(wildcard $(INCDIR)/*.hpp)
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
