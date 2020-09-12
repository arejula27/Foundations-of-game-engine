#---------------------------------------------------------
CC=g++
#---------------------------------------------------------

CPPFLAGS= -std=c++11  # Flags compilacion

all: main

main : main.o
	${CC}  main.o -o main
	
main.o: main.cc 
	${CC} -c ${CPPFLAGS} main.cc -o main.o
