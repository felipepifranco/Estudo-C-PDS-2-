CC = g++ 

all: teste

comunicacao.o: comunicacao.cpp comunicacao.hpp
	${CC} -c comunicacao.cpp -o comunicacao.o

energia.o: energia.cpp energia.hpp
	${CC} -c energia.cpp -o energia.o

R2D2.o: R2D2.hpp R2D2.cpp energia.hpp
	${CC} -c R2D2.cpp -o R2D2.o

main.o: main.cpp energia.hpp R2D2.hpp comunicacao.hpp
	${CC} -c main.cpp -o main.o

teste: main.o R2D2.o energia.o comunicacao.o
	${CC} main.o R2D2.o energia.o comunicacao.o -o teste

clean:
	rm -f *.o *:Zone.Identifier teste