
build = build
cpp = g++
include = include
src = src
entidades = ${src}/entidades

all : vpl_execution

${build}/Pessoa.o: ${entidades}/Pessoa.cpp ${include}/Pessoa.hpp
	${cpp} ${entidades}/Pessoa.cpp -I ${include} -c -o ${build}/Pessoa.o

${build}/Funcionario.o: ${entidades}/Funcionario.cpp ${include}/Funcionario.hpp
	${cpp} ${entidades}/Funcionario.cpp -I ${include} -c -o ${build}/Funcionario.o

${build}/Professor.o: ${entidades}/Professor.cpp ${include}/Professor.hpp
	${cpp} ${entidades}/Professor.cpp -I ${include} -c -o ${build}/Professor.o

${build}/main.o: ${src}/main.cpp
	${cpp} ${src}/main.cpp -I ${include} -c -o ${build}/main.o

vpl_execution: ${build}/Pessoa.o ${build}/Funcionario.o ${build}/Professor.o ${build}/main.o
	${cpp} ${build}/Pessoa.o ${build}/Funcionario.o ${build}/Professor.o ${build}/main.o -o vpl_execution

clean: 
	rm ${build}/*.o vpl_execution