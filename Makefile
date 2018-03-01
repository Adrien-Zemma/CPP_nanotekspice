##
## EPITECH PROJECT, 2018
## nanotekspice
## File description:
##
##

NAME	= nanotekspice

CXX	= g++

RM	= rm -f

SRCS	=	./src/Chipset.cpp \
		./src/Driver.cpp \
		./src/Pin.cpp \
		./src/composents/C_and.cpp\
		./src/composents/C_conter.cpp \
		./src/composents/C_flip_flop.cpp \
		./src/composents/C_four_added.cpp \
		./src/composents/C_invert.cpp \
		./src/composents/C_johnson.cpp \
		./src/composents/C_nand.cpp \
		./src/composents/C_nor.cpp \
		./src/composents/C_or.cpp \
		./src/composents/C_ram.cpp \
		./src/composents/C_register.cpp \
		./src/composents/C_rom.cpp \
		./src/composents/C_xor.cpp \
		./src/parsing/Parse.cpp \
		./src/main.cpp

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS = -I./inc/
CXXFLAGS += -I./inc/composents
CXXFLAGS += -W -Wextra -Werror
CXXFLAGS += -g3
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
	@$(CXX) -c -o $@ $(CXXFLAGS) $<
	@echo -e "[\033[0;32m OK \033[0m] built '$@'"

.PHONY: all clean fclean re
