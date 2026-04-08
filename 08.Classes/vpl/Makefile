CC = g++ -Wall

all: main

Jogador.o: Jogador.cpp Jogador.hpp
	${CC} -c Jogador.cpp -o Jogador.o

Tabuleiro.o: Tabuleiro.cpp Tabuleiro.hpp
	${CC} -c Tabuleiro.cpp -o Tabuleiro.o

Partida.o: Partida.cpp Partida.hpp Jogador.hpp Tabuleiro.hpp
	${CC} -c Partida.cpp -o Partida.o

main.o: main.cpp Partida.hpp Jogador.hpp Tabuleiro.hpp
	${CC} -c main.cpp -o main.o

main: main.o Partida.o Tabuleiro.o Jogador.o
	${CC} main.o Partida.o Tabuleiro.o Jogador.o -o main

clean:
	rm -f *.o main