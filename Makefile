NAME	= program

CXX	= g++

RM	= rm -f

SRCS	= ./src/Chipset.cpp \
	  ./src/Driver.cpp \
	  ./src/Pin.cpp \
	  ./src/composents/C_and.cpp \
	  ./src/main.cpp \
	  ./src/parsing/parse.cpp 

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS = -I./inc/
CXXFLAGS += -I./inc/composents
CXXFLAGS += -W -Wall -Wextra
LDLIBS = 

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
clean:
	@echo -e "\033[1;46m clean OK \033[0m"
	@$(RM) $(OBJS)

fclean:
	@echo -e "\033[1;46m fclean OK \033[0m"
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re: fclean all

%.o: %.cpp
	@g++ -c -o $@ $(CXXFLAGS) $<
	@echo -e "[\033[0;32m OK \033[0m] built '$@'"

.PHONY: all clean fclean re
