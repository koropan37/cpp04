NAME = Polymorphism

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = \
		main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongDog.cpp \
		WrongCat.cpp \


OBJS = $(SRCS:%.cpp=%.o)

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
