# This makefile is used as follows to regenerate files for the run_simulation program:
#	make Barista.o		--  Regenerates Barista.o by compiling
#	make order.o		--  Regenerates order.o by compliling
#	make shopQueue.o	--  Regenerates shopQueue.o by compiling
#	make myShop.o		--  Regenerates myShop.o by compiling
#	run_simulation.o	--  Same as "make run_simulation"

run_simulation: order.o Barista.o shopQueue.o myShop.o
	g++ -g -Wall order.o Barista.o shopQueue.o myShop.o -lm -o run_simulation

order.o: order.cpp order.h
	g++ -g -Wall -c order.cpp 

Barista.o: Barista.cpp Barista.h
	g++ -g -Wall -c Barista.cpp 

shopQueue.o: shopQueue.cpp shopQueue.h
	g++ -g -Wall -c shopQueue.cpp 

myShop.o: myShop.cpp Barista.h shopQueue.h order.h
	g++ -g -Wall -c myShop.cpp 

clean: 
	rm -f run_simulation order.o Barista.o shopQueue.o myShop.o 

all: run_simulation
