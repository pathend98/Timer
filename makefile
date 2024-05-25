all: main

main: main.o
	g++ main.o -o main

main.o:
	g++ -c -Wall main.cpp

clean:
	rm *.o main
