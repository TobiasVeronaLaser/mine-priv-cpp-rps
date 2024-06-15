generic: generic_lib generic_main

generic_lib: generic.cpp  generic.h 
	c++ -c generic.cpp

generic_main: generic_test.cpp generic.o
	c++ generic_test.cpp -o generic_test.o generic.o -lm

prototyp: main.cpp
	c++ main.cpp -o main.o -D PROTOTYPE

main: main.cpp
	c++ main.cpp -o main.o

clear: 
	rm *.o