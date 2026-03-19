CC = g++
CFLAGS = -Wall

# diretorios auxiliares:
BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: vpl_execution

${BUILD_DIR}/Circulo.o: ${INCLUDE_DIR}/Circulo.hpp ${SRC_DIR}/entidades/Circulo.cpp
	${CC} ${CFLAGS} -I  ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Circulo.cpp -o ${BUILD_DIR}/Circulo.o

${BUILD_DIR}/Ponto.o: ${INCLUDE_DIR}/Ponto.hpp ${SRC_DIR}/entidades/Ponto.cpp
	${CC} ${CFLAGS} -I  ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Ponto.cpp -o ${BUILD_DIR}/Ponto.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Ponto.hpp ${INCLUDE_DIR}/Circulo.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I  ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

vpl_execution: ${BUILD_DIR}/main.o ${BUILD_DIR}/Circulo.o ${BUILD_DIR}/Ponto.o
	${CC} ${CFLAGS} -o vpl_execution ${BUILD_DIR}/*.o

clean:
	rm -f ${BUILD_DIR}/* vpl_execution
