# This makefile is used as follows to regenerate files for the teamData program:
#	make analyze_team.o   --  Regenerates analyze_team.o by compiling
#	make Player.o	      --  Regenerates Player.o by compiling
#	make teamData         --  Same as "make teamData"

teamData: analyze_team.o Player.o
	g++ -g -Wall analyze_team.o Player.o -lm -o teamData

analyze_team.o: analyze_team.cpp Player.h
	g++ -g -Wall -c analyze_team.cpp

Player.o: Player.cpp Player.h
	g++ -g -Wall -c Player.cpp

clean:
	rm -f teamData analyze_team.o Player.o

all: teamData