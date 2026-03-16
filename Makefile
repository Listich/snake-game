CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -Iinclude $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)

SRC = src/main.cpp src/snake.cpp
OBJ = obj/main.o src/snake.o
NAME = my_program

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

obj/main.o: src/main.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)