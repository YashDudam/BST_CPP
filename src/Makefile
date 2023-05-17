
CXX = clang++ -std=c++20
CFLAGS = -Wall -Werror -fsanitize=address,leak,undefined

.PHONY: all
all: main

main: main.o Tree.o
	$(CXX) $(CFLAGS) -o main main.o Tree.o

main.o: main.cpp
Tree.o: Tree.cpp Tree.hpp

.PHONY: clean
clean:
	rm -f *.o main
