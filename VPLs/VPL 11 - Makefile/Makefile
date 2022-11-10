gcc=g++
cflags=-std=c++11 -Wall
target=vpl_execution

bld = ./build
src = ./src/entidades
incld = ./include


${bld}/target: ${bld}/funcionario.o ${bld}/pessoa.o ${bld}/professor.o ${bld}/main.o
	${gcc} ${cflags} ${bld}/*.o -o ${target}

${bld}/funcionario.o: ${incld}/Funcionario.hpp ${src}/Funcionario.cpp
	${gcc} ${cflags} -I ./include/ -c ${src}/Funcionario.cpp -o ${bld}/funcionario.o

${bld}/pessoa.o: ${incld}/Pessoa.hpp ${src}/Pessoa.cpp
	${gcc} ${cflags} -I ./include/ -c ${src}/Pessoa.cpp -o ${bld}/pessoa.o

${bld}/professor.o: ${incld}/Professor.hpp ${src}/Professor.cpp
	${gcc} ${cflags} -I ./include/ -c ${src}/Professor.cpp -o ${bld}/professor.o

${bld}/main.o: ${incld}/Professor.hpp ${incld}/Pessoa.hpp ${incld}/Funcionario.hpp ./src/main.cpp
	${gcc} ${cflags} -I ./include/ -c ./src/main.cpp -o ${bld}/main.o
