CC:=gcc
CXX:=g++
LIBS:=-lX11 -lXrandr -lXcursor -lsfml-graphics -lsfml-window -lsfml-system -fsanitize=address -g3
CXX_STANDARD:=-std=c++17
FLAGS:=-Wall -Wextra
DFLAGS:=

compile:
	$(strip $(CXX) $(CXX_STANDARD) $(FLAGS) $(DFLAGS) main.cpp -o main.out $(LIBS))
	./main.out
	
clean:
	rm *.out