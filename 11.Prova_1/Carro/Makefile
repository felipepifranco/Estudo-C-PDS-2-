CC = g++ -Wall

all: main

Motor.o: Motor.cpp Motor.hpp
	${CC} -c Motor.cpp -o Motor.o

Carro.o: Carro.cpp Carro.hpp Motor.hpp
	${CC} -c Carro.cpp -o Carro.o

Batmovel.o: Batmovel.cpp Batmovel.hpp Motor.hpp Carro.hpp 
	${CC} -c Batmovel.cpp -o Batmovel.o

main.o: main.cpp Batmovel.hpp Motor.hpp Carro.hpp 
	${CC} -c main.cpp -o main.o

main: main.o Motor.o Carro.o Batmovel.o
	${CC} main.o Motor.o Carro.o Batmovel.o -o main

clean:
	rm -f *.o main