#include "team_member.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 6){ // Checks if we have enough/too many command line inputs
        puts("Missing command line arguments\n");
        puts("./teamData oldData.txt newData.txt outName.txt numStats numPlayers");
        return 1;
    }

    char* oldDataFile = argv[1];    // initializes oldDataFile to the first input file
    char* newDataFile = argv[2];    // initializes newDataFIle to second input file
    char* outputFile = argv[3];     // initializes outputFile to the third input file
    int numStats = atoi(argv[4]);   // initializes numStats to the fourth commandline input
    int numPlayers = atoi(argv[5]); // initializes numPlayers to the fifth commandline input

    TeamMember* theTeam = (TeamMember*)malloc(numPlayers * sizeof(TeamMember)); // allocates memory for the amount of players
    if (!theTeam) {
        perror("Memory allocation error");
        return 1;
    }

    char firstLine[256]; // stores the first line of the file

    load_data(numPlayers, theTeam, oldDataFile, numStats, firstLine); // loads the data from the oldDataFile
    add_data(numPlayers, theTeam, newDataFile, numStats); // adds the data from the newDataFile
    print_data(numPlayers, theTeam, outputFile, numStats, firstLine); // prints the data to the outputFile

    free_team(theTeam, numPlayers); // releases the memory from the heap
    free(theTeam); // releases the memory from the heap
    
    return 0;
}