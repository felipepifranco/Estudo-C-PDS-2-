CC = g++ -Wall

all: main

Circle.o: Circle.hpp Circle.cpp shape.hpp
	${CC} -c Circle.cpp -o Circle.o

Triangle.o: Triangle.hpp Triangle.cpp shape.hpp
	${CC} -c Triangle.cpp -o Triangle.o

Rectangle.o: Rectangle.hpp Rectangle.cpp shape.hpp
	${CC} -c Rectangle.cpp -o Rectangle.o

shapeFunctions.o: shapeFunctions.hpp shapeFunctions.cpp shape.hpp
	${CC} -c shapeFunctions.cpp -o shapeFunctions.o

main.o: main.cpp shape.hpp shapeFunctions.hpp Rectangle.hpp Triangle.hpp Circle.hpp 
	${CC} -c main.cpp -o main.o

main: Circle.o Triangle.o Rectangle.o shapeFunctions.o main.o
	${CC} Circle.o Triangle.o Rectangle.o shapeFunctions.o main.o -o main

clean:
	rm -f *.o main