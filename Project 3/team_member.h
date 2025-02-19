#ifndef TEAM_MEMBER_H
#define TEAM_MEMBER_H

#include <stdio.h>

typedef struct TeamMember {
    int ID; 
    char lastName[50];
    char firstName[50];
    float* memberData;
} TeamMember;

/*
void load_data(int size, TeamMember theTeam[], const char* filename, int numStats, char* firstLine)

This function reads an initial data file and stores the information into an array of TeamMember structs. 
Each player's statistics are dynamically allocated.

parameters: 
    int size: The number of players in the team
    TeamMember theTeam: An array of TeamMember structs that will hold the team data
    const char* filename: A pointer to the name of the file to read from
    int numStats: The number of statistics for each player
    char* firstLine: A pointer to the first line of the file (the header)

returns: 
    void
*/
void load_data(int size, TeamMember theTeam[], const char* filename, int numStats, char* firstLine);

/*
void add_data(int size, TeamMember theTeam[], const char* filename, int numStats)

This functions purpose is to read new data from another file and updates existing team member statistics by adding new values
 
parameters: 
    int size: The number of players in the team
    TeamMember theTeam: An array of TeamMember structs that will hold the team data
    const char* filename: A pointer to the name of the file to read from
    int numStats: The number of statistics for each player

returns: 
    void
*/
void add_data(int size, TeamMember theTeam[], const char* filename, int numStats);

/*
void print_data(int size, TeamMember theTeam[], const char* filename, int numStats, const char* firstLine)

Prints the updated team data to an output file with the same format as the input file

parameters: 
    int size: The number of players in the team
    TeamMember theTeam: An array of TeamMember structs that will hold the team data
    const char* filename: A pointer to the name of the file to write to
    int numStats: The number of statistics for each player
    const char* firstLine: A pointer to the first line of the file (the header)

returns: 
    void
*/
void print_data(int size, TeamMember theTeam[], const char* filename, int numStats, const char* firstLine);

/*
void free_team(TeamMember theTeam[], int size)

Frees the memory allocated for the team data

parameters: 
    TeamMember theTeam: An array of TeamMember structs that will hold the team data
    int size: The number of players in the team

returns: 
    void
*/
void free_team(TeamMember theTeam[], int size);

#endif
