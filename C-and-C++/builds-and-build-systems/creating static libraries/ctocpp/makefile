all:
	gcc -c cprog.c
	ar rv libcprog.a cprog.o
	g++ cpp.cpp -I./ -L./ -lcprog -o cpp.o

clean:
	rm *.o
	rm *.a
	rm *.out