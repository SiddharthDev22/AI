build: main.o Link.o
	g++ *.o -o build

base1: main.o Link.o
	g++ main.o Link.o -o build

clean:
	rm *.o *.gch build.exe

run: build.exe
	.\build.exe

main.o: main.cpp
	g++ -c main.cpp

Link.o: Link.cpp Link.h
	g++ -c Link.cpp Link.h