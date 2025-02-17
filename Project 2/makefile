# This makefile is used as follows to regenerate files for the runScores program:
#	make analyze_scores.o      --  Regenerates analyze_scores.o by compiling
#	make analysis_functions.o  --  Regenerates anylysis_functions.o by compiling
#	make runScores             --  Same as "make runScores"

runScores: analyze_scores.o analysis_functions.o
	gcc -g -Wall analyze_scores.o analysis_functions.o -lm -o runScores

analyze_scores.o: analyze_scores.c analysis_functions.h
	gcc -g -Wall -c analyze_scores.c

analysis_functions.o: analysis_functions.c analysis_functions.h
	gcc -g -Wall -c analysis_functions.c

clean: 
	rm -f runScores analyze_scores.o analysis_functions.o

all: runScores

