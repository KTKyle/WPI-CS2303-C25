# This makefile is used as follows to regenerate files for the teamData program:
#	make analyze_team.o   --  Regenerates analyze_team.o by compiling
#	make team_member.o    --  Regenerates team_member.o by compiling
#	make teamData         --  Same as "make teamData"

teamData: analyze_team.o team_member.o
	gcc -g -Wall analyze_team.o team_member.o -lm -o teamData
	
analyze_team.o: analyze_team.c team_member.h
	gcc -g -Wall -c analyze_team.c

team_member.o: team_member.c team_member.h
	gcc -g -Wall -c team_member.c

clean: 
	rm -f teamData analyze_team.o team_member.o

all: teamData

