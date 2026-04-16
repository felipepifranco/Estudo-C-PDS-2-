CC = g++ -Wall

all: main


Defesa.o: Defesa.hpp Defesa.cpp
	${CC} -c Defesa.cpp -o Defesa.o

Canhao.o: Canhao.hpp Canhao.cpp Defesa.hpp
	${CC} -c Canhao.cpp -o Canhao.o

CanhaoOrbital.o: CanhaoOrbital.hpp CanhaoOrbital.cpp Canhao.hpp Defesa.hpp
	${CC} -c CanhaoOrbital.cpp -o CanhaoOrbital.o

LancadorMissil.o: LancadorMissil.hpp LancadorMissil.cpp Defesa.hpp
	${CC} -c LancadorMissil.cpp -o LancadorMissil.o

BaseMilitar.o: BaseMilitar.hpp BaseMilitar.cpp Defesa.hpp
	${CC} -c BaseMilitar.cpp -o BaseMilitar.o

main.o: main.cpp LancadorMissil.hpp CanhaoOrbital.hpp Canhao.hpp BaseMilitar.hpp
	${CC} -c main.cpp -o main.o

main: Defesa.o Canhao.o CanhaoOrbital.o LancadorMissil.o BaseMilitar.o main.o

clean:
	rm -f *.o main