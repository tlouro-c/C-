CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Polymorphism

SRC = main.cpp \
	  Animal.cpp \
	  WrongAnimal.cpp \
	  Dog.cpp \
	  Cat.cpp \
	  WrongCat.cpp

OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
