#include "team_member.h"
#include <stdlib.h>
#include <string.h>

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
void load_data(int size, TeamMember theTeam[], const char* filename, int numStats, char* firstLine) {
    FILE* file = fopen(filename, "r"); // Open the file for reading
    if (!file) {
        perror("Error opening old data file");
        exit(1);
    }

    fgets(firstLine, 256, file); // Read the first line of the file

    for (int i = 0; i < size; i++) { // Loop through each player
        fscanf(file, "%d %s %s", &theTeam[i].ID, theTeam[i].firstName, theTeam[i].lastName); // Read the player's ID, first name, and last name
        theTeam[i].memberData = (float*)malloc(numStats * sizeof(float)); // Allocate memory for the player's statistics
        if (!theTeam[i].memberData) { // Check if memory allocation failed
            perror("Memory allocation error");
            exit(1);
        }
        for (int j = 0; j < numStats; j++) { // Loop through each statistic
            fscanf(file, "%f", &theTeam[i].memberData[j]);
        }
    }
    fclose(file);
}

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
void add_data(int size, TeamMember theTeam[], const char* filename, int numStats) {
    FILE* file = fopen(filename, "r"); // Open the file for reading
    if (!file) {
        perror("Error opening new data file");
        exit(1);
    }

    char header[256]; // Read the header of the file
    fgets(header, 256, file);  // Read the first line of the file

    int ID;
    char firstName[50], lastName[50]; 
    float tempData[numStats];

    while (fscanf(file, "%d %s %s", &ID, firstName, lastName) == 3) { // Read the ID, first name, and last name of the player
        for (int j = 0; j < numStats; j++) { // Loop through each statistic
            fscanf(file, "%f", &tempData[j]); // Read the new statistic
        }

        for (int i = 0; i < size; i++) { // Loop through each player
            if (theTeam[i].ID == ID) { // Check if the player ID matches
                for (int j = 0; j < numStats; j++) { // Loop through each statistic
                    theTeam[i].memberData[j] += tempData[j];  // Add the new statistic to the existing statistic
                }
                break; // Exit the loop
            }
        }
    }
    fclose(file);
}

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
void print_data(int size, TeamMember theTeam[], const char* filename, int numStats, const char* firstLine) {
    FILE* file = fopen(filename, "w"); // Open the file for writing
    if (!file) {
        perror("Error opening output file");
        return;
    }

    fprintf(file, "%s", firstLine); // Write the header to the file

    for (int i = 0; i < size; i++) { // Loop through each player
        fprintf(file, "%d\t%s\t%s", theTeam[i].ID, theTeam[i].firstName, theTeam[i].lastName); // Write the player's ID, first name, and last name
        
        for (int j = 0; j < numStats; j++) { // Loop through each statistic
            fprintf(file, "\t%d", (int)theTeam[i].memberData[j]);  // Write the player's statistics
        }
        fprintf(file, "\n"); // Write a newline character
    }

    fclose(file);
}

/*
void free_team(TeamMember theTeam[], int size)

Frees the memory allocated for the team data

parameters: 
    TeamMember theTeam: An array of TeamMember structs that will hold the team data
    int size: The number of players in the team

returns: 
    void
*/
void free_team(TeamMember theTeam[], int size) {
    for (int i = 0; i < size; i++) { // Loop through each player
        free(theTeam[i].memberData); // Free the memory allocated for the player's statistics
    }
}
