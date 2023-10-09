CC:=gcc
CXX:=g++

# this is the whole linking that my lubuntu needs to compile SFML programs
LIBS:=-lX11 -lXrandr -lXcursor -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -fsanitize=address -g3

CXX_STANDARD:=-std=c++17
FLAGS:=-Wall -Wextra
DFLAGS:=

compile:
	$(strip $(CXX) $(CXX_STANDARD) $(FLAGS) $(DFLAGS) main.cpp -o main.out $(LIBS))
	./main.out

clean:
	rm *.out