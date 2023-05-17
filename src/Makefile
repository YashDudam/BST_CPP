
CXX = clang++ -std=c++20
CFLAGS = -Wall -Werror -fsanitize=address,leak,undefined

.PHONY: all
all: main

main: main.o Tree.o Node.o
	$(CXX) $(CFLAGS) -o main main.o Tree.o Node.o

main.o: main.cpp Tree.hpp Node.hpp
Tree.o: Tree.cpp Tree.hpp
Node.o: Node.cpp Node.cpp

.PHONY: clean
clean:
	rm -f *.o main
